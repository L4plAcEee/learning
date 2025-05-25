#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e4 + 5;

int L, N, M, a[MAXN];

bool check(int ans) {
    int cnt = 0;
    for (int i = 0, pre = 0; i <= N; ++i) {
        if (a[i] - pre < ans) cnt++;
        else pre = a[i];
    }
    return cnt <= M;
}


int32_t main() {
    cin >> L >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    a[N] = L;
    
    int l = 0, r = 1e9;
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