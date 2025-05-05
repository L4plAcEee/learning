#include <bits/stdc++.h>
using namespace std;

#define i64 long long
#define u64 unsigned long long

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define psb(x) push_back(x)
#define ppb() pop_back()

#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << x << '\n';
#else
#define dbg(x)
#endif

void sovle(int n) {
    // ——————————————————————————————
    // 修改点 1：直接用浮点计算 2^n 的位数，避免整数组装完整大数再测长
    // ⎡digits = ⌊n·log10(2)⌋ + 1⎤
    int totalDigits = int(log10(2.0) * n + 1);
    cout << totalDigits << '\n';

    // ——————————————————————————————
    // 修改点 2：设置模 10^500，用于快速幂中取低 500 位
    const size_t MOD_DIGITS = 500;

    // 保留原结构：用 vector<u64> 存每位（低位在 [0]）
    vector<u64> ans = {1};      // 最终结果 2^n mod 10^500
    vector<u64> base = {2};     // 当前“底数”，从 2 开始

    // ——————————————————————————————
    // 修改点 3：添加大数乘法函数 mul(a, b)，只保留低 500 位
    auto mul = [&](const vector<u64>& a, const vector<u64>& b) {
        vector<u64> c(MOD_DIGITS, 0);
        // 标准 O(N^2) 乘法，但 i+j 超出 500 则丢弃高位
        for (size_t i = 0; i < a.size() && i < MOD_DIGITS; ++i) {
            for (size_t j = 0; j < b.size() && i + j < MOD_DIGITS; ++j) {
                c[i + j] += a[i] * b[j];
            }
        }
        // 进位归一
        u64 carry = 0;
        for (size_t i = 0; i < MOD_DIGITS; ++i) {
            u64 sum = c[i] + carry;
            c[i] = sum % 10;
            carry = sum / 10;
        }
        // 去掉高位多余 0（保留至少一位 0）
        while (c.size() > 1 && c.back() == 0) c.ppb();
        return c;
    };

    // ——————————————————————————————
    // 修改点 4：用二进制快速幂计算 ans = 2^n mod 10^500
    int exp = n;
    while (exp > 0) {
        if (exp & 1) {
            ans = mul(ans, base);
        }
        base = mul(base, base);
        exp >>= 1;
    }

    // ——————————————————————————————
    // 修改点 5：ans 中保存的是 2^n mod 10^500，现在做减一操作得到 2^n - 1
    u64 borrow = 1;
    for (size_t i = 0; borrow && i < ans.size(); ++i) {
        if (ans[i] >= borrow) {
            ans[i] -= borrow;
            borrow = 0;
        } else {
            ans[i] = ans[i] + 10 - borrow;
            borrow = 1;
        }
    }
    // 去掉高位可能出现的 0
    while (ans.size() > 1 && ans.back() == 0) ans.ppb();

    // ——————————————————————————————
    // 修改点 6：格式化输出末 500 位，左侧不足补 '0'，分 10 行、每行 50 位
    string tail(MOD_DIGITS, '0');
    for (size_t i = 0; i < ans.size() && i < MOD_DIGITS; ++i) {
        // ans[0] 是最低位，对应 tail 最后一个字符
        tail[MOD_DIGITS - 1 - i] = char('0' + ans[i]);
    }
    for (int i = 0; i < 10; ++i) {
        cout << tail.substr(i * 50, 50) << '\n';
    }
}

int main() {
    int P;
    cin >> P;
    sovle(P);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define i64 long long
#define u64 unsigned long long

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define psb(x) push_back(x)
#define ppb() pop_back()

#ifdef LOCAL
#define dbg(x) cerr << #x << " = " << x << '\n';
#else
#define dbg(x)
#endif

void sovle(int n) {
    // ——————————————————————————————
    // 修改点 1：直接用浮点计算 2^n 的位数，避免整数组装完整大数再测长
    // ⎡digits = ⌊n·log10(2)⌋ + 1⎤
    int totalDigits = int(log10(2.0) * n + 1);
    cout << totalDigits << '\n';

    // ——————————————————————————————
    // 修改点 2：设置模 10^500，用于快速幂中取低 500 位
    const size_t MOD_DIGITS = 500;

    // 保留原结构：用 vector<u64> 存每位（低位在 [0]）
    vector<u64> ans = {1};      // 最终结果 2^n mod 10^500
    vector<u64> base = {2};     // 当前“底数”，从 2 开始

    // ——————————————————————————————
    // 修改点 3：添加大数乘法函数 mul(a, b)，只保留低 500 位
    auto mul = [&](const vector<u64>& a, const vector<u64>& b) {
        vector<u64> c(MOD_DIGITS, 0);
        // 标准 O(N^2) 乘法，但 i+j 超出 500 则丢弃高位
        for (size_t i = 0; i < a.size() && i < MOD_DIGITS; ++i) {
            for (size_t j = 0; j < b.size() && i + j < MOD_DIGITS; ++j) {
                c[i + j] += a[i] * b[j];
            }
        }
        // 进位归一
        u64 carry = 0;
        for (size_t i = 0; i < MOD_DIGITS; ++i) {
            u64 sum = c[i] + carry;
            c[i] = sum % 10;
            carry = sum / 10;
        }
        // 去掉高位多余 0（保留至少一位 0）
        while (c.size() > 1 && c.back() == 0) c.ppb();
        return c;
    };

    // ——————————————————————————————
    // 修改点 4：用二进制快速幂计算 ans = 2^n mod 10^500
    int exp = n;
    while (exp > 0) {
        if (exp & 1) {
            ans = mul(ans, base);
        }
        base = mul(base, base);
        exp >>= 1;
    }

    // ——————————————————————————————
    // 修改点 5：ans 中保存的是 2^n mod 10^500，现在做减一操作得到 2^n - 1
    u64 borrow = 1;
    for (size_t i = 0; borrow && i < ans.size(); ++i) {
        if (ans[i] >= borrow) {
            ans[i] -= borrow;
            borrow = 0;
        } else {
            ans[i] = ans[i] + 10 - borrow;
            borrow = 1;
        }
    }
    // 去掉高位可能出现的 0
    while (ans.size() > 1 && ans.back() == 0) ans.ppb();

    // ——————————————————————————————
    // 修改点 6：格式化输出末 500 位，左侧不足补 '0'，分 10 行、每行 50 位
    string tail(MOD_DIGITS, '0');
    for (size_t i = 0; i < ans.size() && i < MOD_DIGITS; ++i) {
        // ans[0] 是最低位，对应 tail 最后一个字符
        tail[MOD_DIGITS - 1 - i] = char('0' + ans[i]);
    }
    for (int i = 0; i < 10; ++i) {
        cout << tail.substr(i * 50, 50) << '\n';
    }
}

int main() {
    int P;
    cin >> P;
    sovle(P);
    return 0;
}
