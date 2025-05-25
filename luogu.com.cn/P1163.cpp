#include <bits/stdc++.h>
using namespace std;

int w_0, w, m;

bool check(int ans) {
    double ratio = 1 + (double)ans / 10000.0;
    double money = w_0;
    for (int i = 1; i <= m; ++i) {
        money *= ratio;
        money -= w;
        if (money <= 1e-6) return true;
    }
    return false;
}

int32_t main() {
    cin >> w_0 >> w >> m;
    int l = 0, r = 30000;
    while (l <= r) {
        int mid = (r - l) / 2 + l;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    double ans = r / 100.0;
    cout << fixed << setprecision(1) << ans << '\n';
}