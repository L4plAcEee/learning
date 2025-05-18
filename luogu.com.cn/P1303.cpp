#include <bits/stdc++.h>
using namespace std;

// A*B Problem - 大整数乘法
// https://www.luogu.com.cn/problem/P1303

using lld = long long;

string string_multi(string a, string b) {
    size_t sa = a.length(), sb = b.length();
    vector<int> res(sa + sb, 0);  // 注意：初始化为 0，而不是 '0'

    // 从最低位开始模拟乘法（从末尾往前）
    for (int i = sa - 1; i >= 0; --i) {
        for (int j = sb - 1; j >= 0; --j) {
            int na = a[i] - '0';
            int nb = b[j] - '0';
            res[i + j + 1] += na * nb; 
        }
    }

    // 处理进位
    for (int i = res.size() - 1; i > 0; --i) {
        res[i - 1] += res[i] / 10;
        res[i] %= 10;
    }

    // 构造字符串结果
    string ans;
    for (int digit : res) {
        ans += (char)(digit + '0');
    }

    // 去除前导零
    // auto it = find_if(ans.begin(), ans.end(), [](char c){ return c != '0'; });
    // if (it == ans.end()) return "0";
    // ans.erase(ans.begin(), it);
    // return ans;
    return ans.substr(ans.find_first_not_of('0') != string::npos ? ans.find_first_not_of('0') : ans.size() - 1);
}    

int main() {
    string a, b;
    cin >> a >> b;
    cout << string_multi(a, b) << endl;
    return 0;
}
