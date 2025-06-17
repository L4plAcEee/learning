#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
int n;

int main() {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    i64 ans = a[0];
    for (int i = 1; i < n; ++i) {
        int min_val = INT_MAX;
        for (int j = i - 1; j >= 0; --j) {
            min_val = min(min_val, abs(a[j] - a[i]));
        }
        ans += min_val;
    }
    cout << ans << '\n';
}