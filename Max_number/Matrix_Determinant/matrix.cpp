#include <cmath>
#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n;
    cin >> n;
    double **a = new double*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new double[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int change = 1;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][i] == 0) {
                double *temp = a[j];
                a[j] = a[i];
                a[i] = temp;
                change *= (-1);
            }
            double t = a[j][i] / a[i][i];
            for (int k = i; k < n; k++)
                a[j][k] -= t * a[i][k];
        }
    }
    double result = 1;
    for (int i = 0; i < n; i++) {
        result *= a[i][i];
    }
    printf("%.lf\n", result * change);
    for (int i = 0; i < n; i++) {
        delete []a[i];
    }
    delete []a;
    a = NULL;
    return 0;
}

