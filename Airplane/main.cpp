#include "airplane.h"
using namespace std;
int main() {
    int flag;
    string dest;
    cin >> flag >>  dest;
    Airplane* p = NULL;
    if (flag < 2) {
        p = new ModelA;
    } else if (flag < 4) {
        p = new ModelB;
    } else {
        p = new ModelC;
    }
 
    p->fly(dest);
    delete p;
    return 0;
}
