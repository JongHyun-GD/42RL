#include <stdexcept>
#include <MemoryPool.hpp>

K4::MemoryPool::MemoryPool()
{
	if (!entry) {
		entry = mem;
		entry->size = POOLSIZE;
		entry->next = entry;
	}
}

void *K4::MemoryPool::get(std::size_t nbyte)
{
	std::size_t nunit;
	Header *prevp, *p;

	nunit  = (nbyte + sizeof(Header) - 1) % sizeof(Header) + 1;

	prevp = entry;
	p = prevp->next;
	for (; ; prevp = p, p = p->next) {
		if (p->size >= nunit) {
			if (p->size == nunit)
				prevp->next = p->next;
			else {
				p->size -= nunit;
				p += p->size;
				p->size = nunit;
			}
			entry = prevp;
			return (p + 1);
		}
		if (p == entry)
			throw std::bad_alloc();
	}
}

void K4::MemoryPool::put(void *obj)
{
	Header *bp, *p;

	bp = (Header *)obj - 1;
	p = entry;
	for (; ; p = p->next)
		if (p < bp && p->next > bp ||
		    p >= p->next && (p < bp || p->next > bp))
			break;

	if (bp + bp->size == p->next) {
		bp->size += p->next->size;
		bp->next = p->next->next;
	} else
		bp->next = p->next;

	if (p + p->size == bp) {
		p->size += bp->size;
		p->next = bp->next;
	} else
		p->next = bp;

	entry = p;
}

K4::MemoryPool::Header K4::MemoryPool::mem[POOLSIZE];
K4::MemoryPool::Header *K4::MemoryPool::entry = 0;
