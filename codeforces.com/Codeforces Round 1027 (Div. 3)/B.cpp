#include <bits/stdc++.h>
using namespace std;

int t, n, k;
string s;

int get_pair(const string& str) {
    int i = 0, j = str.length() - 1, cnt = 0;
    while (i < j) {
        if (str[i] == str[j]) cnt++;
        i++;
        j--;
    }
    return cnt;
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> k >> s;

        int c0 = count(s.begin(), s.end(), '0');
        int c1 = n - c0;

        int max_pair = (c0 / 2) + (c1 / 2);
        int min_pair = abs(c0 - c1) / 2;

        if (k < min_pair || k > max_pair) {
            cout << "No\n";
            continue;
        }

        int pairs = get_pair(s);
        if ((abs(pairs - k) % 2) == 0)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
