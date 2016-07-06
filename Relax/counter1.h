#ifndef COUNTER1_H_
#define COUNTER1_H_

class counter1 {
    public:
        void operator() ();
        counter1() {}
        ~counter1() {}
        static int counter;
        static void count() {
            counter++;
        }
};
int counter1::counter = 0;
void counter1::operator() () {
    void count();
}
#endif

