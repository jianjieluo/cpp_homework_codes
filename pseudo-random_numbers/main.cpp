#include <iostream>
#include "random_my.h"
using namespace std;
using namespace RAND_GEN;

void test_calc() {
    mod_my mod_1(9223372036854775807, 16807, 1);
    if (mod_1.calc(9223372036854775) != 7443261233741790514 ||
        mod_1.calc(922337203685477580) != 6456360425798331301 ||
        mod_1.calc(9223372036852222220) != 9223371993936639099 ||
        mod_1.calc(922337203685473330) != 6456360425726901551 ||
        mod_1.calc(9223372022254775806) != 9223126654654759001)
        cout << "Your calc() is wrong.\n";
    else cout << "Pass all tests for calc().\n";
}

void test_engin() {
    linear_congruential_engine_my lce;
    int count = 1000;
    int num[1001] = {0};
    while (count--) num[lce()%5]++;
    if (num[0] != 216 || num[1] != 190 ||
        num[2] != 203 || num[3] != 216 ||
        num[4] != 175) {
        cout << "Your engin class is wrong in generator.\n";
        return;
    } else if (lce.min() != (lce.increment == 0u ? 1u : 0u)) {
        cout << "Your engin class is wrong in min().\n";
        return;
    } else if (lce.max() != (lce.modulus - 1u)) {
        cout << "Your engin class is wrong in max().\n";
        return;
    }
    else cout << "Pass all tests for class engin.\n";
}

void hard_test() {
    long long m, a, c, n, num[5] = {0};
    unsigned long long s;
    unsigned long long discard_n;
    cin >> m >> a >> c >> s;
    mod_my mod_1(m, a, c);
    for (int i = 0; i < 5; i++) {
        cin >> n;
        cout << "(MOD CALC) ";
        cout << n << ": " << mod_1.calc(n) << endl;
    }
    linear_congruential_engine_my lce(m, a, c, s);
    cin >> discard_n;
    lce.discard(discard_n);
    cin >> n;
    while (n--) num[lce()%5]++;
    for (int i = 0; i < 5; i++) {
        cout << "(ENGIN) ";
        cout << i << ": " << num[i] << endl;
    }
}

int main() {
    int t;
    cin >> t;
    if (t == 0) {
        test_calc();
        test_engin();
    } else {
        hard_test();
    }
    return 0;
}

/*

Carsons good friend Hannibal helps him design the frame of this
two classes. If you are good, you should design them by your own.

namespace RAND_GEN {
class mod_my {
  public:
    long long m, a, c;
    mod_my(long long, long long, long long);
    long long calc(long long);
};

class linear_congruential_engine_my {
public:
    long long multiplier, increment, modulus;
    unsigned long long default_seed_my, seed_my;
    mod_my mod_temp;

    linear_congruential_engine_my();

    linear_congruential_engine_my(
    long long _m, long long _a, long long _c, long long _s);

    void seed(unsigned long long);

    long long min();
    long long max();

    void discard(unsigned long long);

    long long operator()();
};
}  // namespace RAND_GEN
*/
