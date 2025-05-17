#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000005

int n, m, a[MAXN];

int solve(int num) {
    int i = 0, j = n - 1;
    while (i <= j) {
        int mid =  i + (j - i) / 2;
        if (a[mid] < num) {
            i = mid + 1;
        } else {
            j = mid - 1;
        }
    }
    return a[i] == num ? i + 1 : -1;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    while (m--) {
        int tmp = 0;
        cin >> tmp;
        cout << solve(tmp) << ' ';
    }
    return 0;
}