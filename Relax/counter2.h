#ifndef COUNTER2_H_
#define COUNTER2_H_

namespace counter2 {
    static int counter = 0;
    static void set(int x) {
        counter2::counter = x;
    }
    static void count() {
        counter2::counter++;
    }
}

#endif
