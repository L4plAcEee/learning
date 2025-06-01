#include <bits/stdc++.h>
using namespace std;

int n;
set<vector<int>> ans;
vector<int> expr(3, 0);
int cost[10] = {
    6,
    2,
    5,
    5,
    4,
    5,
    6,
    3,
    7,
    6
};

int get_cost(int num) {
    if (num == 0) return cost[0];
    int total = 0;
    while (num > 0) {
        total += cost[num % 10];
        num /= 10;
    }
    return total;
}

void dfs(int idx) {
    if (idx == 3) {
        if ((reduce(expr.begin(), expr.end(), 0, [](int sum, int &num) {
            return sum + get_cost(num);
        }) + 4 != n) || (expr[0] + expr[1] != expr[2])) return;
        ans.insert(expr);
        return;
    }
    for (int i = 0; i <= 1111; ++i) {
        expr[idx] = i;
        if (get_cost(expr[idx]) >= n - 4) continue;
        if (idx > 0 && get_cost(expr[idx]) + get_cost(expr[idx - 1]) >= n - 4) continue;

        dfs(idx + 1);
    }
}

int32_t main() {
    cin >> n;
    dfs(0);
    cout << ans.size() << '\n';
} 