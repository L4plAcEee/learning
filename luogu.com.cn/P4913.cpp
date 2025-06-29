#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
int n;
int node[MAXN][2];

int get_depth(int id) {
    if (node[id][0] == 0 && node[id][1] == 0) return 0;
    return max(get_depth(node[id][0]) + 1, get_depth(node[id][1]) + 1);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> node[i][0] >> node[i][1];
    }
    cout << get_depth(1) + 1 << '\n';
}