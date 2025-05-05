// P1591 阶乘数码
// https://www.luogu.com.cn/problem/P1591
#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << x << '\n'
#else
#define dbg(x)
#endif

struct fastio {
    fastio() {
        ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    }
} fastio;

void multiply(vector<int> &digits, int n) {
    int carry = 0;
    for (int i = 0; i < digits.size(); ++i) {
        int prod = digits[i] * n + carry;
        carry = prod / 10;
        digits[i] = prod % 10;
    }
    while (carry) {
        digits.push_back(carry % 10);
        carry /= 10;
    }
}

int countDigitInFactorial(int n, int a) {
    vector<int> digits = {1};

    for (int i = 2; i <= n; ++i) {
        multiply(digits, i);
    }
    return count(all(digits), a);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, a;
        cin >> n >> a;        
        cout << countDigitInFactorial(n, a) << endl;
    }
    return 0;
}