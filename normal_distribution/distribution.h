#ifndef DISTRIBUTION_H_
#define DISTRIBUTION_H_
#include <limits>
#include <cmath>
#include <algorithm>
#include <cstddef>
using namespace RAND_GEN;




class adptor {
public:
    adptor() {}
    double min() const {
        return static_cast<double>(0);
    }
    double max() const {
        return static_cast<double>(1);
    }
    double operator()() {
        size_t b = static_cast<size_t>(std::numeric_limits<double>::digits);
        s

};


#endif
