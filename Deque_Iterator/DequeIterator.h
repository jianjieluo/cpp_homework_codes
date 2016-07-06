#include
#include
#define BUFFER_SIZE \
  10  // the number of elements in each buffer, do not changethis value.

using namespace std;

template <typename T>
sturct DequeIterator {
  typedef DequeIterator iterator;
  typedef DequeIterator const_iterator;
  static size_t buffer_size() { return BUFFER_SIZE; }
  typedef random_access_iterator_tag iterator_category;  // iterator tag.
  typedef T value_type;
  typedef Ptr pointer;
  typedef Ref reference;
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;
  typedef T** map_pointer;
  typedef DequeIterator self;
  T* cur;    // pointer, pointing to the current element.
  T* first;  // pointer, pointing to the first element in current buffer.
  T* last;   // pointer, pointing to the last element in current buffer.
  map_pointer node;  // T**, pointing to the location in the map(controller)
  // where this value points to the start address in the buffer.
  DequeIterator(T * x, map_pointer y)  // y's value is the address of first
                                       // buffer's address.
      explicit DequeIterator(map_pointer y);
  DequeIterator();
}
