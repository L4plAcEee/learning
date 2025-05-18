#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> ans;

// 当前配料编号、第 i 个配料，和当前总克数 deli
void dfs(vector<int>& path, int idx, int deli) {
    if (idx == 10) { // 已经放了10种配料
        if (deli == n) ans.push_back(path); // 总克数恰好为 n，合法方案
        return;
    }
    for (int j = 1; j <= 3; ++j) { // 每种配料可以放1到3克
        path.push_back(j);
        dfs(path, idx + 1, deli + j); // 放下一种配料
        path.pop_back();
    }
}

void solve() {
    cin >> n;
    vector<int> path;
    dfs(path, 0, 0);
    cout << ans.size() << '\n';
    for (auto& a : ans) {
        for (auto& num : a) cout << num << ' ';
        cout << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
