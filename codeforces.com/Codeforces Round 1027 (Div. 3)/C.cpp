#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // 如果 n=0，直接输出 0
        if (n == 0) {
            cout << 0 << "\n";
            continue;
        }

        long long answer = 0;

        // 记录当前块（“相邻数值差为 1 的区段”）的长度
        int currentBlockLen = 0;

        // lastDistinct = 上一个已处理的“不同的数值”；初始化为 a[0]-2，
        // 使得第一个数值 a[0] 一定视作新块的开始
        int lastDistinct = a[0] - 2;

        for (int i = 0; i < n; ++i) {
            // 跳过重复值，只要与上一个不同就算一次“新数值”
            if (i > 0 && a[i] == a[i-1]) {
                continue;
            }
            int v = a[i];
            if (v - lastDistinct == 1) {
                // 与上一个不同数值正好相差 1，属于同一个连续块
                currentBlockLen++;
            } else {
                // 遇到新的块（或首块），先把前一块的贡献加上，再开启新块
                if (currentBlockLen > 0) {
                    answer += (currentBlockLen + 1) / 2;
                }
                currentBlockLen = 1;  // 本次 v 自己作为新块的第一个元素
            }
            lastDistinct = v;
        }
        // 最后一个块的贡献
        if (currentBlockLen > 0) {
            answer += (currentBlockLen + 1) / 2;
        }

        cout << answer << "\n";
    }

    return 0;
}
