#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll

int n, X;

void solve() {
    cin >> n >> X;
    long long sum1 = 0;
    vector<int> items(1, 0);
    vector<int> hap(1, 0);
    for (int i = 0, ai, bi, wi; i < n; ++i) {
        cin >> ai >> bi >> wi;
        if ((ai - bi) - bi >= 0) {
            sum1 += wi;
            X += ai - bi - bi;
        } else {
            items.push_back(-(ai - bi - bi));
            hap.push_back(wi);
        }
    }
    #ifdef LOCAL
    {
        cout << "sum1 == " << sum1 << '\n';
        cout << "X == " << X << '\n';
    }
    #endif
    vector<vector<int>> dp(items.size(), vector<int>(X + 1, 0));
    for (int i = 1; i < items.size(); ++i) {
        for (int j = 0; j <= X; ++j) {
            if (j - items[i] >= 0) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - items[i]] + hap[i]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << sum1 + dp[items.size() - 1][X] << '\n';
}

int32_t main() {
    #ifdef LOCAL
    cout << '\n';
    #endif
    solve();
}