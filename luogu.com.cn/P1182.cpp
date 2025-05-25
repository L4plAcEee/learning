#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int N, M, A[MAXN];

bool check(int ans) {
    int cnt = 1, sum = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] > ans) return false;
        if (sum + A[i] > ans) {
            cnt++;
            sum = 0;
        }
        sum += A[i];
        if (cnt > M) return false;
    }
    return true;
}

int32_t main() {
    cin >> N >> M;
    for (int i = 0; i < N ; ++i) {
        cin >> A[i];
    }

    int l = 1, r =  1e9;
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