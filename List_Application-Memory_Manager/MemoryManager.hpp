#ifndef MEMORYMANAGER_H_
#define MEMORYMANAGER_H_
#define __STL_NOTHROW throw()
#include <malloc.h>

template <class _Tp> class MemoryManager {
 public:
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;
  typedef _Tp *pointer;
  typedef const _Tp *const_pointer;
  typedef _Tp &reference;
  typedef const _Tp &const_reference;
  typedef _Tp value_type;

  template <class _Tp1> struct rebind { typedef MemoryManager<_Tp1> other; };
  // MemoryManager() __STL_NOTHROW : _M_pool(NULL);
  // MemoryManager(const MemoryManager &) __STL_NOTHROW : _M_pool(NULL);
  MemoryManager() { freeslot = 0; }
  // MemoryManager(const MemoryManager &);
  // template <class _Tp1>
  // MemoryManager(const MemoryManager<_Tp1> &) __STL_NOTHROW;
  ~MemoryManager() __STL_NOTHROW {
    while (freeslot != NULL) {
      slot_pointer temp = freeslot;
      freeslot = freeslot->next;
      delete temp;
    }
  }
  // 元素取址
  pointer address(reference __x) const { return &__x; }
  const_pointer address(const_reference __x) const { return &__x; }

  // 分配和收回一个内存空间
  _Tp *allocate(size_type __n, const void * = 0) {
    if (freeslot != NULL) {
      pointer result = reinterpret_cast<pointer>(freeslot);
      freeslot = freeslot->next;
      return result;
    } else {
      pointer result = reinterpret_cast<pointer>(new Slot);
      return result;
    }
  }
  // __p is not permitted to be a null pointer.
  void deallocate(pointer __p, size_type __n) {
    if (__p != NULL) {
      slot_pointer temp = reinterpret_cast<slot_pointer>(__p);
      temp->next = freeslot;
      freeslot = temp;
    }
  }

  // 可达到的最多元素
  size_type max_size() const __STL_NOTHROW {
    size_type counter = 0;
    slot_pointer ptr = freeslot;
    while (ptr != NULL) {
      ptr = ptr->next;
      ++counter;
    }
    return counter;
  }

  void construct(pointer __p, const _Tp &__val) { new (__p) value_type(__val); }

  void destroy(pointer __p) { __p->~value_type(); }

 private:
  union Slot {
    value_type element;
    Slot *next;
  };

  typedef Slot slot_type;
  typedef Slot *slot_pointer;

  slot_pointer freeslot;
};
#endif

