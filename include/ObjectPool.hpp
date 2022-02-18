#ifndef OBJECTPOOL_HPP
#define OBJECTPOOL_HPP

#include <cstddef>
#include <stdexcept>

#define OPcreate(T, n) ObjectPool<T>::create(n)
#define OPdestroy(T) ObjectPool<T>::destroy()
#define OPget(T) ObjectPool<T>::get()
#define OPput(T, obj) ObjectPool<T>::put(obj)
#define OPgrow(T, n) ObjectPool<T>::grow(n)

namespace K4 {
	template <typename T>
	class ObjectPool {
	public:
		static void create(std::size_t size) {
			if (exist)
				return ;
			exist = true;
			while (size-- > 0)
				add(new List());
		}

		static void destroy() {
			exist = false;
			while (head)
				delete pop();
		}

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
		ObjectPool();

		struct List {
			T data;
			List *next;
		};

		static void add(List *list) {
			list->next = head;
			head = list;
		}

		static List *pop() {
			List *ret = head;
			head = head->next;
			return ret;
		}

		static List *head;
		static bool exist;
	};
}

template <typename T>
typename K4::ObjectPool<T>::List *K4::ObjectPool<T>::head = 0;

template <typename T>
bool K4::ObjectPool<T>::exist = false;

#endif
