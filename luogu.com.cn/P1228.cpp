#include <bits/stdc++.h>
using namespace std;

struct Tile { 
    int x, y, t; 
};

vector<Tile> ans;

// 在 (sx,sy) 为左上角、边长为 size 的棋盘上，以 (hole_x,hole_y) 为“缺口”进行铺砖
void solve(int sx, int sy, int size, int hole_x, int hole_y) {
    if (size == 1) return;  // 1x1 无需再放
    int half = size >> 1;
    int midx = sx + half - 1, midy = sy + half - 1;
    // 计算原缺口属于哪个象限：0=左上,1=右上,2=左下,3=右下
    int quad = (hole_x > midx) * 2 + (hole_y > midy);

    // 在中心位置放一块 tromino，形状 id = quad+1
    // 拐角 (cx,cy) 的选择须对应题目中 4 种 L 形编号
    int cx = midx + ((quad/2) ^ 1);
    int cy = midy + ((quad%2) ^ 1);
    ans.push_back({cx, cy, quad + 1});

    // 对四个子棋盘递归
    for (int q = 0; q < 4; ++q) {
        int nsx = sx + (q/2) * half;
        int nsy = sy + (q%2) * half;
        int nhx, nhy;
        if (q == quad) {
            // 保持原缺口
            nhx = hole_x;  
            nhy = hole_y;
        } else {
            // 用刚放 tromino 的“虚拟缺口”
            nhx = midx + (q/2);
            nhy = midy + (q%2);
        }
        solve(nsx, nsy, half, nhx, nhy);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, x, y;
    cin >> k >> x >> y;
    int n = 1 << k;

    solve(1, 1, n, x, y);

    // 输出所有放置操作
    for (auto &t : ans) {
        cout << t.x << " " << t.y << " " << t.t << "\n";
    }
    return 0;
}
