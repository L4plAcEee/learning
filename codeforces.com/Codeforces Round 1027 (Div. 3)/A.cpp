#include <bits/stdc++.h>
using namespace std;
int t;
string s;

void f(int num) {
    for (int i = 0; i <= 100; ++i) {
        for (int j = 0; j <= 100; ++j) {
            if ((i + j) * (i + j) == num) {
                cout << i << ' ' << j << '\n';
                return;
            }
        }
    }
    cout << -1 << '\n';
}

int32_t main() {
    cin >> t;
    while (t--) {
        cin >> s;
        int num = stoi(s);
        f(num);
    }
}