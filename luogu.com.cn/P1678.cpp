#include <bits/stdc++.h>
using namespace std;

const int MAXM = 10e5 + 5;

int m, n, a[MAXM];

int32_t main() {
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    sort(a, a + m);
    long long ans = 0;
    while (n--) {
        int s = 0;
        cin >> s;
        auto it = lower_bound(a, a + m, s);
        if (it != a + m && *it == s) continue;

        int front = INT_MAX, back = INT_MAX;
        if (it != a) front = *(it - 1);
        if (it != a + m) back = *it;

        ans += min(abs(s - front), abs(s - back));
    }
    cout << ans << '\n';
}