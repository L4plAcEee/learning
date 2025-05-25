#include <bits/stdc++.h>
using namespace std;

int n, p;
vector<int> a, b;

bool check(double ans) {
    double t = 0;
    for (int i = 0; i < n; ++i) {
        double needed = ans * a[i];  // 在时间ans内设备i需要的总能量
        if (needed > b[i]) {         // 如果需要的能量超过初始存储
            double deficit = needed - b[i];  // 缺少的能量
            t += deficit / p;                // 需要充电的时间
        }
        if (t > ans) return false;   // 如果总充电时间超过ans，不可行
    }
    return true;
}

int main() {
    cin >> n >> p;
    
    a.resize(n);
    b.resize(n);
    int total_consumption = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        total_consumption += a[i];
    }
    
    if (check(1e15)) {
        cout << -1 << endl;
        return 0;
    }
    double l = 0, r = 1e15;  // 改为double类型
    
    // 浮点二分，迭代足够次数保证精度
    for (int iter = 0; iter < 100; ++iter) {
        double mid = (l + r) / 2.0;
        if (check(mid)) {
            l = mid;  // 如果可行，答案可能更大
        } else {
            r = mid;  // 如果不可行，答案应该更小
        }
    }
    
    cout << fixed << setprecision(10) << l << endl;
    return 0;
}