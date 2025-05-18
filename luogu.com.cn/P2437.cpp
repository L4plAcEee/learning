#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define MAXN 1005

int m, n= 0;
string memo[MAXN];
// string dp[MAXN];

string str_add(string const &a, string const &b) {
    string ret = string(max(a.length(), b.length()) + 1, '0');
    int i = a.length() - 1, j = b.length() - 1, k = ret.length() - 1, carry = 0;
    while (i >= 0 || j >= 0 || carry) {
        int x = (i >= 0 ? a[i--] - '0' : 0);
        int y = (j >= 0 ? b[j--] - '0' : 0);
        int sum = x + y + carry;
        carry = sum / 10;
        ret[k--] = '0' + (sum % 10);
    }
    while (ret.size() > 1 && ret[0] == '0') ret.erase(0, 1);
    return ret;
} 

string memorize_dfs(int i) {
    if (i < m) return "0";
    if (i == m) return "1";
    if (!memo[i].empty()) return memo[i];
    return memo[i] = str_add(memorize_dfs(i - 1), memorize_dfs(i - 2));
}

string dp(int i) {
    string pre1 = "1", pre2 = "0", cur = "-1";
    if (i == n) return pre2;
    if (i + 1 == n) return pre1;
    for (int idx = i + 1; idx <= n; ++idx) {
        cur = str_add(pre1, pre2);
        pre2 = pre1;
        pre1 = cur;
    }
    return cur;
}

int32_t main() {
    #ifdef LOCAL
    cout << '\n';
    #endif
    cin >> m >> n;
    // cout << memorize_dfs(n) << '\n';  
    cout << dp(m) << '\n';
    return 0;
}
