#include <bits/stdc++.h>
using namespace std;

int n, m;

void solve() {
    cin >> n >> m;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; cin >> v[i].first >> v[i++].second);
    sort(v.begin(), v.end(), [](auto &a, auto &b) {
        if (a.second != b.second) return a.second > b.second;
        else return a.first < b.first;
    });
    int score_line = v[m * 3 / 2 - 1].second;
    auto it = upper_bound(v.begin(), v.end(), score_line, [](int v, auto &a) {
        return v > a.second;
    });
    #ifdef LOCAL
    {
        cout << <<"idx = " << it - v.begin() << " and " <<(*it).first << " : " << (*it).second << '\n';
    }
    #endif
    cout << score_line << ' ' << it - v.begin() << '\n';
    for (auto i = v.begin(); i != it ; ++i) {
        cout << (*i).first << ' ' << (*i).second << '\n';
    }
}
int32_t main() {
    #ifdef LOCAL
    cout << "开始测试\n";
    #endif

    solve();
}