#include <bits/stdc++.h>
using namespace std;

/*
  “D. Come a Little Closer” 修正版：

  思路：
    对每个测试用例，先一次遍历收集所有点的：
      x_min, x_min2, cntMinX, x_max, x_max2, cntMaxX;
      y_min, y_min2, cntMinY, y_max, y_max2, cntMaxY;
    然后再对每只怪物 i 枚举“把它移动”的情况：
      1. 删除它后，剩余 n-1 只怪物的最小包围矩形边界 (xL, xR, yL, yR)；
      2. 记 w = xR - xL + 1, h = yR - yL + 1,
         如果 n-1 < w*h，则答案候选 = w*h；否则（n-1 == w*h），候选 = min((w+1)*h, w*(h+1))。
    取所有候选最小即为最终答案。

  时间复杂度：每个测试用例 O(n)，总和 ∑n ≤ 2×10^5。
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        vector<long long> X(n), Y(n);
        for (int i = 0; i < n; i++) {
            cin >> X[i] >> Y[i];
        }

        // n=1 时单独处理：无论如何也得选一个 1×1 的矩形
        if (n == 1) {
            cout << 1 << "\n";
            continue;
        }

        // 初始化 x 方向的极值与次极值及其计数
        const long long INF = (long long)4e18;
        long long x_min = INF,  x_min2 = INF;
        long long x_max = -INF, x_max2 = -INF;
        int cntMinX = 0, cntMaxX = 0;

        // 初始化 y 方向的极值与次极值及其计数
        long long y_min = INF,  y_min2 = INF;
        long long y_max = -INF, y_max2 = -INF;
        int cntMinY = 0, cntMaxY = 0;

        // 第一次遍历：统计 x_min, x_min2, cntMinX, x_max, x_max2, cntMaxX；同理 y
        for (int i = 0; i < n; i++) {
            long long x = X[i], y = Y[i];

            // —— 处理 x 方向最小值／次最小值 及 计数 ——
            if (x < x_min) {
                x_min2 = x_min;
                x_min  = x;
                cntMinX = 1;
            }
            else if (x == x_min) {
                cntMinX++;
            }
            else if (x < x_min2) {
                x_min2 = x;
            }

            // —— 处理 x 方向最大值／次最大值 及 计数 ——
            if (x > x_max) {
                x_max2 = x_max;
                x_max  = x;
                cntMaxX = 1;
            }
            else if (x == x_max) {
                cntMaxX++;
            }
            else if (x > x_max2) {
                x_max2 = x;
            }

            // —— 处理 y 方向最小值／次最小值 及 计数 ——
            if (y < y_min) {
                y_min2 = y_min;
                y_min  = y;
                cntMinY = 1;
            }
            else if (y == y_min) {
                cntMinY++;
            }
            else if (y < y_min2) {
                y_min2 = y;
            }

            // —— 处理 y 方向最大值／次最大值 及 计数 ——
            if (y > y_max) {
                y_max2 = y_max;
                y_max  = y;
                cntMaxY = 1;
            }
            else if (y == y_max) {
                cntMaxY++;
            }
            else if (y > y_max2) {
                y_max2 = y;
            }
        }

        // 枚举“删除第 i 只怪物”后需要的最小代价，取最小
        long long answer = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            long long x = X[i], y = Y[i];

            // 1. 计算删除它后，剩余点的 x 左边界 new_xL
            long long new_xL;
            if (x != x_min) {
                new_xL = x_min;
            }
            else {
                // x == x_min
                if (cntMinX >= 2) new_xL = x_min;
                else              new_xL = x_min2;
            }

            // 2. 删除它后，剩余点的 x 右边界 new_xR
            long long new_xR;
            if (x != x_max) {
                new_xR = x_max;
            }
            else {
                // x == x_max
                if (cntMaxX >= 2) new_xR = x_max;
                else              new_xR = x_max2;
            }

            // 3. 删除它后，剩余点的 y 下边界 new_yL
            long long new_yL;
            if (y != y_min) {
                new_yL = y_min;
            }
            else {
                if (cntMinY >= 2) new_yL = y_min;
                else              new_yL = y_min2;
            }

            // 4. 删除它后，剩余点的 y 上边界 new_yR
            long long new_yR;
            if (y != y_max) {
                new_yR = y_max;
            }
            else {
                if (cntMaxY >= 2) new_yR = y_max;
                else              new_yR = y_max2;
            }

            // 计算剩余 n-1 个点的包围矩形尺寸
            long long w = new_xR - new_xL + 1;  // 宽
            long long h = new_yR - new_yL + 1;  // 高
            long long area_base = w * h;

            // 如果 (n-1) < w*h，说明矩形内部有空格，不需要扩充
            // 否则 (n-1) == w*h，矩形被完全占满，必须在 w 或 h 上扩充 1
            long long cost_i;
            if ((long long)(n - 1) < area_base) {
                cost_i = area_base;
            } else {
                // 拆不开只能扩充
                cost_i = min( (w + 1) * h,  w * (h + 1) );
            }

            answer = min(answer, cost_i);
        }

        cout << answer << "\n";
    }

    return 0;
}
