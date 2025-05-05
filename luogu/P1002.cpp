#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << '\n'
#define int long long

int xb, yb, xc, yc;
vector<vector<int>> grid(21, vector<int>(21, 0));
vector<vector<int>> dp(21, vector<int>(21, 0));

vector<pair<int, int>> dir = {
    {-1, -2},
    {-2, -1},
    {-2, 1},
    {-1, 2},
    {1, 2},
    {2, 1},
    {2, -1},
    {1, -2}
};


int DP(int n, int m) {
    dp[n][m] = 1;
    for (int i = n; i >= 0; --i) {
        for (int j = m; j >= 0; --j) {
            if (!grid[i][j]) {
                int res = 0;
                if (i < n) res += dp[i + 1][j];
                if (j < m) res += dp[i][j + 1];
                dp[i][j] = res;
            }
        }
    }
    return dp[0][0];
}

void solve() {
    cin >> xb >> yb >> xc >> yc;
    grid[xc][yc] = 1;
    grid[xb][yb] = 1;
    for (int i = 0; i < dir.size(); ++i) {
        int pos_x = xc + dir[i].first, pos_y = yc + dir[i].second;
        if (pos_x >= 0 && pos_x < grid.size() && pos_y >= 0 && pos_y < grid.size()) {
            grid[pos_x][pos_y] = 1;
            dp[pos_x][pos_y] = 0;
        }
    }
    cout << DP(xb, yb) << '\n';
}

int32_t main() {
    solve();
}