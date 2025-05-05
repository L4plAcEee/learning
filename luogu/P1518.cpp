// P1518 [USACO2.4] 两只塔姆沃斯牛 The Tamworth Two
// https://www.luogu.com.cn/problem/P1518
#include <bits/stdc++.h>
using namespace std;

using i128 = __int128_t;
using u128 = __uint128_t;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << '\n';
#else
#define debug(x)
#endif

vector<vector<char>> grid(10, vector<char>(10, '.'));
vector<vector<int>> f_visited(10, vector<int>(10, -1));
vector<vector<int>> c_visited(10, vector<int>(10, -1));
int fx, fy, fdir = 0, cx, cy, cdir = 0;

vector<int> dir_x = {0, 1, 0, -1};
vector<int> dir_y = {-1, 0, 1, 0};

// 使用一个哈希表或集合记录系统状态
set<tuple<int, int, int, int, int, int>> visited_states;

int solve() {
    int cnt = 0, next_x, next_y;
    while (fx != cx || fy != cy) {
        // 检查系统状态是否出现过
        auto state = make_tuple(fx, fy, fdir, cx, cy, cdir);
        if (visited_states.count(state)) {
            return 0;  // 系统状态重复，将永远不会相遇
        }
        visited_states.insert(state);
        
        // 农夫移动
        next_x = fx + dir_x[fdir], next_y = fy + dir_y[fdir];
        if (next_x >= 0 && next_x < 10 && next_y >= 0 && next_y < 10 && grid[next_y][next_x] != '*') {
            fx = next_x;
            fy = next_y;
        } else {
            fdir = (fdir + 1) % 4;
        }
        
        // 牛移动
        next_x = cx + dir_x[cdir], next_y = cy + dir_y[cdir];
        if (next_x >= 0 && next_x < 10 && next_y >= 0 && next_y < 10 && grid[next_y][next_x] != '*') {
            cx = next_x;
            cy = next_y;
        } else {
            cdir = (cdir + 1) % 4;
        }
        
        cnt++;
    }
    
    return cnt;
}

int main() {
    
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'F') fx = j, fy = i;
            if (grid[i][j] == 'C') cx = j, cy = i;
        }
    }
    cout << solve();
    return 0;
}