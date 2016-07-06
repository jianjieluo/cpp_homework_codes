#include "MemoryManager.hpp"
using namespace std;

MemoryManager::MemoryManager() { freeslot = 0; }
const_pointer MemoryManager::address(const_reference __x) const { return &__x; }

pointer MemoryManager::address(reference __x) const { return &__x; }

_Tp *MemoryManager::allocate(size_type __n, const void *) {
  if (freeslot != NULL) {
    pointer result = reinterpret_cast<pointer>(freeslot);
    freeslot = freeslot->next;
    return result;
  } else {
    pointer result = reinterpret_cast<pointer>(&(new Slot));
    return result;
  }
}

void MemoryManager::construct(pointer __p, const _Tp &__val) {
  new (__p) value_type(__val);
}

void MemoryManager::deallocate(pointer __p, size_type __n) {
  if (__p != NULL) {
    slot_pointer temp = reinterpret_cast<slot_pointer>(__p);
    temp->next = freeslot;
    freeslot = temp;
  }
}

void MemoryManager::destroy(pointer __p) { __p->~value_type(); }

