#include <bits/stdc++.h>
using namespace std;

const int MAXN = 11;
int n, s[MAXN], b[MAXN], ans = INT_MAX;

void dfs(int idx, int tot_s, int tot_b, bool used) {
    if (idx == n) {
        if (used) ans = min(ans, abs(tot_s - tot_b));
        return;
    }
    dfs(idx + 1, tot_s * s[idx], tot_b + b[idx], true);
    dfs(idx + 1, tot_s, tot_b, used);
}

int32_t main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i] >> b[i];
    }
    dfs(0, 1, 0, false); // 初始未选择任何食材
    cout << ans << '\n';
    return 0;
}
