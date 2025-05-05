// P1009 [NOIP 1998 普及组] 阶乘之和
// https://www.luogu.com.cn/problem/P1009
#include <bits/stdc++.h>
using namespace std;
using lld = long long;

string _add(string a, string b) {
    size_t sa = a.length(), sb = b.length();
    if (sa < sb) {
        a = string(sb - sa, '0') + a;// 这里粗心写错了，浪费我一小时tmd
    } else {
        b = string(sa - sb, '0') + b;
    }
    int carry =  0;
    for (int i = a.length() - 1; i >= 0; --i) {
        int na = a[i] - '0', nb = b[i] - '0';
        int sum = na + nb + carry;
        carry = sum / 10;
        a[i] =  (sum % 10) + '0';
    }
    if (carry) {
        a = "1" + a;
    }
    return a;
}

string _multi(string a, string b) {
    size_t sa = a.length(), sb = b.length();
    vector<lld> res(sa + sb, 0);
    for (int i = sa - 1; i >= 0; --i) {
        for (int j = sb - 1; j >= 0; --j) {
            res[i + j + 1] += (a[i] - '0') * (b[j] - '0');
        }
    }
    for (int i = res.size() - 1; i > 0; --i) {
        res[i - 1] += res[i] / 10;
        res[i] %= 10;
    }
    stringstream ans;
    for (auto d : res)
        ans << d; // 或者 to_string(d)

    string s = ans.str();
    size_t pos = s.find_first_not_of('0');
    return pos == string::npos ? "0" : s.substr(pos);
}

string fac(int n) {
    if (n == 0) return "1";
    return _multi(to_string(n), fac(n - 1));
}

void test() {
    cout << "add: " << _add("999", "5001") << '\n';
    cout << "multi: " << _multi("20", "30") << '\n';
    cout << "fac: " << fac(3) << '\n';
}

int main() {
    test();
    int n;
    cin >> n;
    string res = "0";
    for (int i = 1; i <= n; ++i) {
        res = _add(res, fac(i));
    }
    cout << res;
    return 0;
}