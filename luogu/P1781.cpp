#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
    vector<pair<string, int>> v(n);
    for(int i = 1; i <= n; ++i) {
        cin >> v[i - 1].first;
        v[i - 1].second = i;
    }
    // lambda版本
    sort(v.begin(), v.end(), [](pair<string, int> &a, pair<string, int> &b) {
        if (a.first.length() != b.first.length()) 
            return a.first.length() > b.first.length();
        return a > b;
    });
    cout << v[0].second << '\n' << v[0].first << '\n';
}


int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    solve();
    return 0;
}