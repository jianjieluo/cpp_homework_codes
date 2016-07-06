#ifndef TIMER_H_
#define TIMER_H_
#include <cstdio>
#include <iostream>
static int _clock = 0;
inline void clock_f();

namespace TIC_TOC {
class timer {
    public:
        timer();
        ~timer();
        double getAllRdtsc(int i);
        void tic_f(int count);
        void toc_f(int count);
        void tictoc(FILE* _stdout);
        double* tic;
        double* toc;
};
class timer_controller {
    private:
        timer* timePiece;
    public:
        timer_controller();
        ~timer_controller();
        void create(int n);
        timer& operator[](int i);
        void display(FILE* _stdout);
};
}  // namespace TIC_TOC

void clock_f() {
    _clock += 50;
}

TIC_TOC::timer::timer() {
    tic = new double[5]();
    toc = new double[5]();
}

TIC_TOC::timer::~timer() {
    delete []tic;
    delete []toc;
}

double TIC_TOC::timer::getAllRdtsc(int i) {
    return (toc[i] - tic[i]);
}

void TIC_TOC::timer::tic_f(int count) {
    tic[count] = _clock;
}

void TIC_TOC::timer::toc_f(int count) {
    toc[count - 1] = _clock;
}

void TIC_TOC::timer::tictoc(FILE* _stdout) {
    printf("line 0 - 1: %0.3lfms\n", getAllRdtsc(0) / 1000);
    printf("line 1 - 2: %0.3lfms\n", getAllRdtsc(1) / 1000);
    printf("line 2 - 3: %0.3lfms\n", getAllRdtsc(2) / 1000);
    printf("line 3 - 4: %0.3lfms\n", getAllRdtsc(3) / 1000);
    printf("line 4 - 5: %0.3lfms\n", getAllRdtsc(4) / 1000);
}

TIC_TOC::timer_controller::timer_controller() {
    timePiece = NULL;
}

TIC_TOC::timer_controller::~timer_controller() {
    delete []timePiece;
}

void TIC_TOC::timer_controller::create(int n) {
    timePiece = new timer[n]();
}

TIC_TOC::timer& TIC_TOC::timer_controller::operator[] (int i) {
    return (timePiece[i]);
}

void TIC_TOC::timer_controller::display(FILE* _stdout) {
    double sum = 0;
    for (int i = 0; i < 5; ++i)
        sum += (timePiece[0].getAllRdtsc(i) / 1000);
    printf("#Timer_1: %.3lfms\n", sum);
    sum = 0;
    for (int i = 0; i < 5; ++i)
        sum += (timePiece[1].getAllRdtsc(i) / 1000);
    printf("#Timer_2: %.3lfms\n", sum);
}
#endif
