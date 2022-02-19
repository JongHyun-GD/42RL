#ifndef OBJECTPOOL_HPP
#define OBJECTPOOL_HPP

#include <cstddef>
#include <stdexcept>
#include "Singleton.hpp"

namespace K4 {
	template <typename T>
	class ObjectPool: public Singleton< ObjectPool<T> > {
	public:
		static T &get() {
			if (!head)
				throw ObjectPoolEmpty();
			return pop()->data;
		}

		static void put(T *obj) {
			add((List *)(obj));
		}

		static void grow(std::size_t size) {
			while (size-- > 0)
				add(new List());
		}

		struct ObjectPoolEmpty : public runtime_error {
			ObjectPoolEmpty(): runtime_error("K4::ObjectPool: "
							 "Object pool empty")
			{}
		};

	private:
		friend class Singleton<ObjectPool>;

		struct List {
			T data;
			List *next;
		};

		const static std::size_t POOLSIZE = 128 * 1024;
		static List *head;

		ObjectPool() {
			for (std::size_t i = 0; i < POOLSIZE; i++)
				add(new List());
		}

		~ObjectPool() {
			while (head)
				delete pop();
		}

		static void add(List *list) {
			list->next = head;
			head = list;
		}

		static List *pop() {
			List *ret = head;
			head = head->next;
			return ret;
		}
	};
}

template <typename T>
typename K4::ObjectPool<T>::List *K4::ObjectPool<T>::head;

#endif
