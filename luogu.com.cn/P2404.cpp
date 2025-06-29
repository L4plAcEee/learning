#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> path;

void dfs(int sum, int num) {
    if (sum == n)
        for (int i = 0; i < path.size(); ++i) 
            cout << path[i] << (i == path.size() - 1 ? '\n' : '+');

    for (int i = num; i + sum <= n && i < n; ++i) {
        path.push_back(i);
        dfs(sum + i, i);
        path.pop_back();
    }
}

int main() {
    cin >> n;
    dfs(0, 1);
}