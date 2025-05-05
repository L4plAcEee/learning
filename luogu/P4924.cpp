// P4924 [1007] 魔法少女小Scarlet
// https://www.luogu.com.cn/problem/P4924
#include <bits/stdc++.h>
using namespace std;

// 顺时针旋转：B[i][j] = A[n - j - 1][i]
// 逆时针旋转：B[i][j] = A[j][n − i − 1]
void rotate(vector<vector<int>> &mat, int x, int y, int r, int z) {
    --x;
    --y;
    int sz = 2 * r + 1;
    vector<vector<int>> temp(sz, vector<int>(sz, 0));
    int start_i = x - r, start_j = y - r;
    for (int i = 0; i < temp.size(); ++i) {
        for (int j = 0; j < temp.size(); ++j) {
            // if (z) {
            //     cout << "Accessing: mat[" << start_i + j << "][" << start_j + (sz - i - 1) << "]" << endl;
            // } else {
            //     cout << "Accessing: mat[" << start_i + (sz - j - 1) << "][" << start_j + i << "]" << endl;
            // }
            
            temp[i][j] = z ? mat[start_i + j][start_j + (sz - i - 1)] : mat[start_i + (sz - j - 1)][start_j + i];
        }
    }
    for (int i = 0; i < temp.size(); ++i) {
        for (int j = 0; j < temp.size(); ++j) {
            mat[start_i + i][start_j + j] = temp[i][j];
        }
    }
}

void print_mat(vector<vector<int>> &mat) {
    for (auto &rows : mat) {
        for (auto &gird : rows) {
            cout << gird << ' ';
        }
        cout << '\n';
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int> (n, 0));
    for (int i = 0, cnt = 1; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mat[i][j] = cnt++;
        }
    }
    while (m--) {
        int x, y, r, z;
        // cin >> x >> y >> y >> z;  ❌ 错误：重复读取 y，r 永远是未初始化的值
        cin >> x >> y >> r >> z;  // 👈 这样才是四个参数正确读取！
        rotate(mat, x, y, r, z);
    }
    print_mat(mat);
    return 0;
}