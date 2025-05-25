#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int MAXL = 1e7;

int L, N, K, a[MAXN];


bool check(int ans) {
    if (ans == 0) return true;
    int cnt = 0;
    for (int i = 1; i < N; ++i) {
        cnt += (a[i] - a[i - 1] - 1) / ans;
        if (cnt > K) return false;  // 提前剪枝
    }
    return cnt <= K;
}

int32_t main() {
    cin >> L >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    int l = 1, r = L;
    while (l <= r) {
        int mid = (r - l) / 2 + l;
        if (check(mid)) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << l << '\n';
}