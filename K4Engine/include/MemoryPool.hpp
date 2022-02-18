#ifndef MEMORYPOOL_HPP
#define MEMORYPOOL_HPP

#include <cstddef>
#include <Singleton.hpp>

namespace K4 {
	class MemoryPool: public Singleton<MemoryPool> {
	public:
		static void *get(std::size_t nbyte);
		static void put(void *obj);

	private:
		friend class Singleton<MemoryPool>;

		MemoryPool();

		struct Header {
			std::size_t size;
			union {
				Header *next;
				std::max_align_t nouse;
			};
		};

		static const std::size_t POOLSIZE = 128 * 1024;
		static Header mem[POOLSIZE];
		static Header *entry;
	};
}
#endif
