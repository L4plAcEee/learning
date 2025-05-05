// P1067 [NOIP 2009 普及组] 多项式输出
// https://www.luogu.com.cn/problem/P1067
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << '\n'
#else
#define debug(X)
#endif

int n;
vector<int> inputs;

string solve() {
    string res = "";
    
    // 找到第一个非0系数的项
    int first_nonzero = 0;
    while (first_nonzero <= n && inputs[first_nonzero] == 0) {
        first_nonzero++;
    }
    
    // 如果所有系数都是0，返回"0"
    if (first_nonzero > n) {
        return "0";
    }
    
    // 处理第一项（最高次非零项）
    int highest_power = n - first_nonzero;
    
    if (inputs[first_nonzero] == 1 && highest_power > 0) {
        // 系数为1且次数>0，只需要写x部分
        res = "";
    } else if (inputs[first_nonzero] == -1 && highest_power > 0) {
        // 系数为-1且次数>0，只需要写-x部分
        res = "-";
    } else {
        // 其他情况，写出系数
        res = to_string(inputs[first_nonzero]);
    }
    
    // 添加变量和指数部分
    if (highest_power > 1) {
        res += "x^" + to_string(highest_power);
    } else if (highest_power == 1) {
        res += "x";
    }
    // highest_power == 0时不需要添加x
    
    // 处理剩余的项
    for (int i = first_nonzero + 1; i <= n; i++) {
        int power = n - i;
        
        if (inputs[i] == 0) continue; // 跳过系数为0的项
        
        // 添加符号
        if (inputs[i] > 0) {
            res += "+";
        } else {
            res += "-";
        }
        
        // 添加系数（只有当系数的绝对值不为1或次数为0时才需要）
        int abs_coef = abs(inputs[i]);
        if (abs_coef != 1 || power == 0) {
            res += to_string(abs_coef);
        }
        
        // 添加变量和指数
        if (power > 1) {
            res += "x^" + to_string(power);
        } else if (power == 1) {
            res += "x";
        }
        // power == 0时不需要添加x
    }
    
    return res;
}

int main() {
    cin >> n;
    inputs.resize(n + 1, 0);
    for (int i = 0; i <= n; i++) {
        cin >> inputs[i];
    }
    cout << solve() << '\n';
    return 0;
}