#include <bits/stdc++.h>
using namespace std;

long long gcd(int a, int b) {
    if (a == 0 && b == 0) return 0; // 处理 gcd(0, 0)
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(int a, int b) {
    if (a == 0 || b == 0) return 0; // 处理 lcm(0, x) 或 lcm(x, 0)
    return (long long)a / gcd(a, b) * b;  // 使用 long long 来避免溢出
}

int main() {
    vector<pair<int, int>> testCases = {
        {6, 9},         // 公因数：3，最小公倍数：18
        {0, 5},         // gcd = 5, lcm = 0
        {7, 0},         // gcd = 7, lcm = 0
        {0, 0},         // gcd = 0, lcm = 0
        {12, 12},       // 相等情况
        {8, 32},        // 一个是另一个的倍数
        {123456, 789012} // 大数测试
    };

    for (auto &[a, b] : testCases) {
        cout << "a = " << a << ", b = " << b << " | gcd = " << gcd(a, b)
             << ", lcm = " << lcm(a, b) << endl;
    }

    return 0;
}
