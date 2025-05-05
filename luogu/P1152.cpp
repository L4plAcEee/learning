#include <bits/stdc++.h>
using namespace std;

int n;
int s[1001] = {0};

void solve() {
    cin >> n;
    vector<int> v1(n);
    for (int &num : v1) cin >> num;
    
    // 重置数组s
    memset(s, 0, sizeof(s));
    bool flag = true;
    for (int i = 1; i < n; ++i) {
        int diff = abs(v1[i] - v1[i - 1]);
        // 如果差值超出范围1~(n-1)，直接判定为非欢乐跳
        if (diff < 1 || diff > n - 1) {
            flag = false;
            break;
        }
        s[diff] = 1;
    }
    // 只有当所有差值都在范围内，才需要检查是否包含所有1到n-1的数
    if (flag) {
        for (int i = 1; i <= n - 1; ++i) {
            if (s[i] != 1) {
                flag = false;
                break;
            }
        }
    }
    cout << (flag ? "Jolly" : "Not jolly") << '\n';
}
int32_t main() {
    #ifdef LOCAL
    cout << '\n';
    #endif
    solve();
}