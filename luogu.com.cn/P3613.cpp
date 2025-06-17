#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<unordered_map<int, int>> a(n + 1);
    while (q--) {
        int op = 0;
        cin >> op;
        if (op == 1) {
            int i, j , k;
            cin >> i >> j >> k;
            a[i][j] = k;
        } else {
            int i, j;
            cin >> i >> j;
            cout << a[i][j] << '\n';
        }
    }
}