#include <bits/stdc++.h>
using namespace std;

int main() {
    int w, n;
    cin >> w >> n;
    vector<int> m(n);
    for (int i = 0; i < n; cin >> m[i++]);
    sort(m.begin(), m.end());
    int l = 0, r = n - 1, cnt = 0;
    while (l < r) {
        if (m[l] + m[r] > w) {
            r--;
        } else {
            l++;
            r--;
        }
        cnt++;
    }
    if (l == r) cnt++;
    cout << cnt << '\n';
}