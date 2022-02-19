#include <stdexcept>
#include "MemoryPool.hpp"

K4::MemoryPool::MemoryPool() {}

K4::MemoryPool::~MemoryPool()
{
	for (auto p : map) {
		std::stack<void *> &stack = p.second;
		while (!stack.empty()) {
			free(stack.top());
			stack.pop();
		}
	}
}

/* Because we return void *, we need strictest aligned memory
 * max_align_t is for that purpose
 */

union BlockInfo {
	std::size_t mapKey;
	std::max_align_t nouse;
};

#define UNIT 128

/* public */

void K4::MemoryPool::preAlloc(std::size_t size, std::size_t n)
{
	for (std::size_t i = 0; i < n; i++)
		allocOne(size);
}

void *K4::MemoryPool::get(std::size_t size)
{
	std::size_t mapKey = (size + UNIT - 1) / UNIT;
	std::stack<void *> &stack = map[mapKey];

	if (stack.empty())
		allocOne(size);
	void *p = stack.top();
	stack.pop();
	return ((BlockInfo *)p + 1);
}

void K4::MemoryPool::put(void *p)
{
	BlockInfo *bp = (BlockInfo *)p - 1;
	std::size_t mapKey = bp->mapKey;
	map[mapKey].push(bp);
}

/* private */

void K4::MemoryPool::allocOne(std::size_t size)
{
	std::size_t mapKey = (size + UNIT - 1) / UNIT;
	std::size_t roundUpSize = mapKey * UNIT;
	BlockInfo *p = (BlockInfo *)malloc(roundUpSize + sizeof(BlockInfo));
	if (!p)
		throw std::bad_alloc();
	p->mapKey = mapKey;
	map[mapKey].push(p);
}

std::map<std::size_t, std::stack<void *>> K4::MemoryPool::map;
