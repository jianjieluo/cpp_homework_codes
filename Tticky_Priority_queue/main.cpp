#include <deque>
#include <iostream>
#include <cstdio>
using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    deque<int> job;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        job.push_back(temp);
    }
    int time = 0;
    while (m != -1) {
        bool judge = true;
        for (int i = 1; i < n; ++i) {
            if (job[0] < job[i]) judge = false;
        }
        if (!judge) {
            job.push_back(job[0]);
        }
        job.pop_front();
        m--;
        if (judge) n--;
        if (judge) time++;
        if ((judge && m == -1)) {
            cout << time << endl;
        }
        if ((!judge) && m == -1) {
            m = n - 1;
        }
    }
    return 0;
}
