#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()

int main() {
    int t;
    cin >> t;
    vector<int> ans;
    while (t--) {
        int n;
        cin >> n;
        ans.resize(2 * n, 0);
        unordered_set<int> s;

        for (int i = 0, temp; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> temp;
                if ((i + j + 1) < 2 * n) {
                    s.insert(temp);
                    ans[i + j  + 1] = temp;
                }
            }
        }
        for (int i = 1; i <= 2 * n; ++i) {
            if (s.find(i) == s.end()) {
                ans[0] = i;
            }
        }
        // cout << "out: ";
        for_each(all(ans), [](int n) {
            cout << n << ' ';
        });
        cout << '\n';
        // cout << "end out" << '\n';
    }

    return 0;
}