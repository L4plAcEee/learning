#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    string ans;
    string tmp;
    while (t--) {
        for (int i = 1; i <= 3; ++i) {
            cin >> tmp;
            ans += tmp[0];
        }
        cout << ans << '\n';
        ans = "";        
    }
    return 0;
}