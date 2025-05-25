#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cout << #x << " : " << x << '\n';

using i64 = long long;

const int MAXN = 1e6 + 1;

i64 N, M, a[MAXN];


bool verify(int H) {
    i64 sum = 0;
    for (int i = 0; i < N; ++i) {
        if (a[i] > H) {
            sum += (a[i] - H);
            if (sum >= M) return true;
        }
    }
    return sum >= M;
}

int32_t main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    i64 l = 0, r = *max_element(a, a + N);
    while (l <= r) {
        i64 mid = (r - l) / 2 + l;
        if (verify(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    dbg(l);
    dbg(r);
    cout << r << '\n';
}