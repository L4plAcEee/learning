#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> pushed(n), poped(n);
        for (int i = 0; i < n; ++i) cin >> pushed[i];
        for (int i = 0; i < n; ++i) cin >> poped[i];

        int i = 0, j = 0; // i 入栈位置，j 出栈位置
        for (int k = 0; k < n; ++k) { // 遍历 pushed
            pushed[i++] = pushed[k]; // 入栈（复用数组）
            while (i > 0 && pushed[i - 1] == poped[j]) { // 如果栈顶元素等于当前出栈元素
                i--; // 栈顶出栈
                j++; // 出栈指针后移
            }
        }

        if (i == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}