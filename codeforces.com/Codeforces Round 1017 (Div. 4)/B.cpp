#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, l, r;
        cin >> n >> m >> l >> r;
        int sub_l = l, sub_r = r;
        while (sub_r - sub_l > m) {
            if (abs(sub_r) > abs (sub_l)) {
                sub_r--;
            } else {
                sub_l++;
            }
        }
        cout << sub_l << ' ' << sub_r << '\n';
    }
    return 0;
}