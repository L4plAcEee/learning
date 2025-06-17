#include <bits/stdc++.h>
using namespace std;

int get_val(int a, int b) {
    return (a - b) * (a - b);
}

int main() {
    int n;
    cin >> n;
    vector<int> s(n + 1);
    s[0] = 0;
    for (int i = 1; i < n + 1; cin >> s[i++]);
    sort(s.begin(), s.end());
    int l = 0, r = n;
    long long ans = 0;
    while (l < r) {
        ans += get_val(s[l], s[r]);
        l++;
        ans += get_val(s[l], s[r]);
        r--;
    }
    cout << ans << '\n';
}