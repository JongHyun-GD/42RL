#ifndef MEMORYPOOL_HPP
#define MEMORYPOOL_HPP

#include <cstddef>
#include <Singleton.hpp>
#include <map>
#include <stack>

namespace K4 {
	class MemoryPool: public Singleton<MemoryPool> {
	friend class Singleton<MemoryPool>;

	public:
		static void preAlloc(std::size_t size, std::size_t n);
		static void *get(std::size_t size);
		static void put(void *p);

	private:
		MemoryPool();
		~MemoryPool();
		static void allocOne(std::size_t size);
		static std::map<std::size_t, std::stack<void* > > map;
	};
}
#endif
