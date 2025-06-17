#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int n, m;
    cin >> n >> m;
    vector<int> a;

    for (int i = 1; i <= n; ++i) {
        a.push_back(i);
    }

    auto it = a.begin();
    while (!a.empty()) {
        for (int i = 1; i < m; ++i) {
            ++it;
            if (it == a.end()) it = a.begin();
        }
        cout << *it << ' ';
        it = a.erase(it);
        if (it == a.end()) it = a.begin();
    }

    return 0;
}
