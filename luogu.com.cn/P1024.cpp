#include <bits/stdc++.h>
using namespace std;

double a, b, c, d;

// 三次函数
double f(double x) {
    return ((a * x + b) * x + c) * x + d;
}

// 二分求根 [l, r]
double solve(double l, double r) {
    double fl = f(l), mid;
    for (int it = 0; it < 100; ++it) {
        mid = (l + r) / 2;
        double fm = f(mid);
        if (fl * fm < 0) {
            r = mid;
        } else {
            l = mid;
            fl = fm;
        }
    }
    return mid;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b >> c >> d;
    vector<double> roots;
    const double eps = 1e-8, dedup = 1e-4;

    // 扫描 [-100,100)
    for (int i = -100; i < 100 && roots.size() < 3; ++i) {
        double x1 = i, x2 = i + 1;
        double f1 = f(x1), f2 = f(x2);

        // 整数点根
        if (fabs(f1) < eps) {
            double r = x1;
            bool is_dup = false;
            for (double t : roots)
                if (fabs(t - r) < dedup) { is_dup = true; break; }
            if (!is_dup) roots.push_back(r);
        }
        // 严格异号时二分
        if (f1 * f2 < 0) {
            double r = solve(x1, x2);
            bool is_dup = false;
            for (double t : roots)
                if (fabs(t - r) < dedup) { is_dup = true; break; }
            if (!is_dup) roots.push_back(r);
        }
    }
    // 末端 x=100
    if (roots.size() < 3 && fabs(f(100)) < eps) {
        double r = 100.0;
        bool is_dup = false;
        for (double t : roots)
            if (fabs(t - r) < dedup) { is_dup = true; break; }
        if (!is_dup) roots.push_back(r);
    }

    sort(roots.begin(), roots.end());
    cout << fixed << setprecision(2);
    for (int i = 0; i < 3; ++i) {
        cout << roots[i] << (i + 1 < 3 ? ' ' : '\n');
    }
    return 0;
}
