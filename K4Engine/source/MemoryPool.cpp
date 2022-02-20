#include <stdexcept>
#include "MemoryPool.hpp"

using namespace K4;

MemoryPool::MemoryPool() {}

MemoryPool::~MemoryPool()
{
	for (auto p : map) {
		std::stack<void *> &stack = p.second;
		while (!stack.empty()) {
			free(stack.top());
			stack.pop();
		}
	}
}

/* put 함수가 포인터만 받고 사이즈를 따로 받지 않기 때문에, 메모리 풀에 있는
 * 어떤 사이즈를 담는 스택에 넣어야 할지 알 수 없습니다. 따라서 메모리를 할당
 * 할 때부터, 이 메모리가 어떤 스택에 소속된 것인지를 메모리 앞부분에 표시해둘
 * 필요가 있습니다. 그걸 위한 것이 BlockInfo 의 stack 입니다.
 *
 * get 함수가 void * 를 리턴하기 때문에, 가장 엄격한 메모리 정렬 제한을 따르는
 * 주소를 리턴해야 하는데, 그래서 stack 과 max_align_t 를 공용체로 묶어줄 필요가
 * 있습니다.
*/
union BlockInfo {
	std::stack<void *> *stack;
	max_align_t nouse;
};

/* 정말로 모든 사이즈마다 따로따로 스택을 가지고 있으면 메모리 낭비가 너무 심하기
 * 때문에, UNIT 만큼의 단위마다 스택을 가지고 있기로 했습니다.
 * 예를 들면, UNIT 이 128 이라고 할때, 1 ~ 128 바이트의 요청이 들어오면 모두
 * 128 바이트의 메모리를 리턴하고, 129 ~ 256 바이트의 요청에는 모두 256 바이트를
 * 리턴하는 식입니다. 그래서 맵의 키도 실제 사이즈가 아니라 1 ~ 128 은 1, 129 ~
 * 256 은 2 처럼 사용합니다.
*/
#define UNIT 128

/* public */

void MemoryPool::preAlloc(size_t size, size_t n)
{
	size_t mapKey = (size + UNIT - 1) / UNIT;
	size_t roundUpSize = mapKey * UNIT;
	size_t allocSize = roundUpSize + sizeof(BlockInfo);
	std::stack<void *> &stack = map[mapKey];

	while (n-- > 0)
		allocOne(&stack, allocSize);
}

void *MemoryPool::get(size_t size)
{
	size_t mapKey = (size + UNIT - 1) / UNIT;
	std::stack<void *> &stack = map[mapKey];

	if (stack.empty()) {
		size_t roundUpSize = mapKey * UNIT;
		size_t allocSize = roundUpSize + sizeof(BlockInfo);

		allocOne(&stack, allocSize);
	}
	void *p = stack.top();
	stack.pop();
	return ((BlockInfo *)p + 1);
}

void MemoryPool::put(void *p)
{
	BlockInfo *bp = (BlockInfo *)p - 1;
	bp->stack->push(bp);
}

/* private */

void MemoryPool::allocOne(std::stack<void *> *stack, size_t allocSize)
{
	BlockInfo *p = (BlockInfo *)malloc(allocSize);
	if (!p)
		throw std::bad_alloc();
	p->stack = stack;
	stack->push(p);
}

std::map<size_t, std::stack<void *>> MemoryPool::map;
