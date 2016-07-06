#include <iostream>
#include <cassert>
#include <time.h>
#include <vector>

#include "MemoryManager.hpp"
#include "StackAlloc.hpp"

/* Adjust these values depending on how much you trust your computer */
// #define ELEMS 520000
#define REPS 50

int main() {
  clock_t start;
  int ELEMS;
  std::cin >> ELEMS;
  /* Use the default allocator */
  // StackAlloc<int, std::allocator<int> > stackDefault;
  // start = clock();
  // for (int j = 0; j < REPS; j++) {
  //   assert(stackDefault.empty());
  //   for (int i = 0; i < ELEMS / 4; i++) {
  //     // Unroll to time the actual code and not the loop
  //     stackDefault.push(i);
  //     stackDefault.push(i);
  //     stackDefault.push(i);
  //     stackDefault.push(i);
  //   }
  //   for (int i = 0; i < ELEMS / 4; i++) {
  //     // Unroll to time the actual code and not the loop
  //     stackDefault.pop();
  //     stackDefault.pop();
  //     stackDefault.pop();
  //     stackDefault.pop();
  //   }
  // }
  // std::cout << "Default Allocator Time: ";
  // std::cout << (((double)clock() - start) / CLOCKS_PER_SEC) << "\n\n";

  /* Use MemoryManager */
  StackAlloc<int, MemoryManager<int> > stackPool;
  start = clock();
  for (int j = 0; j < REPS; j++) {
    assert(stackPool.empty());
    for (int i = 0; i < ELEMS / 4; i++) {
      // Unroll to time the actual code and not the loop
      stackPool.push(i);
      stackPool.push(i);
      stackPool.push(i);
      stackPool.push(i);
    }
    for (int i = 0; i < ELEMS / 4; i++) {
      // Unroll to time the actual code and not the loop
      stackPool.pop();
      stackPool.pop();
      stackPool.pop();
      stackPool.pop();
    }
  }

  std::cout << "Done Processing allocation." << std::endl;
  std::cout << "You can run the program locally to check the difference "
               "between MemoryManager and std::Alloc"
            << std::endl;
  // std::cout << "MemoryManager Allocator Time: ";
  // std::cout << (((double)clock() - start) / CLOCKS_PER_SEC) << "\n\n";

  return 0;
}


