#include <bits/stdc++.h>
using namespace std;


const int MAXN = 1e5 + 5;


int n, k, a[MAXN];

bool check(int len) {
    if (len == 0) return true;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += a[i] / len;
        if (ans >= k) return true;
    }
    return false;
}

int32_t main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    int l = 0, r = 1e8;
    while (l <= r) {
        int mid = (r - l) / 2 + l;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << r << '\n';
}