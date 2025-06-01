#include <bits/stdc++.h>
using namespace std;

int n, a[9], used[10] = {0};

void dfs(int idx) {
    if (idx == n) {
        for (int i = 0; i < n; ++i) {
            cout << setw(5) << a[i];
        }
        cout << '\n';
        return ;
    }
    for (int i = 1; i <= n; ++i) {
        a[idx] = i;
        if (used[i] == 1) continue;
        used[i] = 1;
        dfs(idx + 1);
        used[i] = 0;
    }
}

int main() {
    cin >> n;
    dfs(0);
}