#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MAXN 200005

int a[MAXN];
int N, C;

int32_t main() {
    cin >> N >> C;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    int cnt = 0;
    sort(a, a + N);
    for (int i = 0; i < N; ++i) {
        cnt += upper_bound(a, a + N, a[i] - C) - lower_bound(a, a + N, a[i] - C);
    }
    cout << cnt << '\n';
}