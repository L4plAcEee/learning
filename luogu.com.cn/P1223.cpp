#include <bits/stdc++.h>
using namespace std;

struct people {
    int time;
    int idx;
};


const int MAXN = 1e3 + 1;
int n;
people p[MAXN];

int32_t main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        p[i].idx = i + 1;
        cin >> p[i].time;
    }
    sort(p, p + n, [](auto &a, auto& b){
        return a.time < b.time;
    });
    double waiting_time = 0.0;
    for (int i = 0; i < n; ++i) {
        cout << p[i].idx << ' ';
        waiting_time += p[i].time * (n - i - 1);
    }
    cout << '\n';
    cout << fixed << setprecision(2) << waiting_time / n << '\n';
}