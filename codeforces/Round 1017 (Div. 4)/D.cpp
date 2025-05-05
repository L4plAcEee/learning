#include <bits/stdc++.h>
using namespace std;

void solve(int t) {
    while (t--) {
        string p, cmp;
        cin >> p >> cmp;
        int i = 0, j = 0;
        bool flag = true;
        // 使用 && 只在两个字符串都有字符时进入循环
        while (i < p.length() && j < cmp.length()) {
            int li = i, lj = j;

            while (i < p.length() && p[i] == p[li]) ++i;
            while (j < cmp.length() && cmp[j] == cmp[lj]) ++j;
            
            // 检查当前两组字符是否一致（字符必须相同）
            if (p[li] != cmp[lj]) {
                flag = false;
                break;
            }
            int cnt_p = i - li, cnt_cmp = j - lj;
            // 检查 cmp 的数量是否在合法范围内
            if (cnt_cmp < cnt_p || cnt_cmp > 2 * cnt_p) {
                flag = false;
                break;
            }
        }
        // 遍历结束后，如果两字符串未同时结束则说明不匹配
        if (i != p.length() || j != cmp.length()) {
            flag = false;
        }
        cout << (flag ? "YES" : "NO") << '\n';
    }
}




int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    solve(t);
    return 0;
}