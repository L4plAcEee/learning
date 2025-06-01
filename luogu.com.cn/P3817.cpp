#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, x;
    cin >> n >> x;
    
    vector<long long> a(n + 1);  // 1-indexed for convenience
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    long long sum = 0;
    
    // 贪心：从左到右处理每对相邻的盒子
    for (int i = 1; i < n; ++i) {
        if (a[i] + a[i + 1] > x) {
            // 需要从右边盒子吃掉的糖果数
            long long eat = a[i] + a[i + 1] - x;
            sum += eat;
            a[i + 1] -= eat;  // 更新右边盒子的糖果数
        }
    }
    
    cout << sum << endl;
    return 0;
}