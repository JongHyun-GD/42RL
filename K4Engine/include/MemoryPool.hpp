#ifndef MEMORYPOOL_HPP
#define MEMORYPOOL_HPP

#include <stddef.h>
#include <Singleton.hpp>
#include <map>
#include <stack>

namespace K4 {
	class MemoryPool: public Singleton<MemoryPool> {
	friend class Singleton<MemoryPool>;

	public:
		static void preAlloc(size_t size, size_t n);
		static void *get(size_t size);
		static void put(void *p);

	private:
		MemoryPool();
		~MemoryPool();
		static void allocOne(std::stack<void *> *stack, size_t size);
		static std::map<size_t, std::stack<void *>> map;
	};
}
#endif
