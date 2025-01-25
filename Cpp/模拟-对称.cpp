#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    
    vector<vector<vector<int>>> image(n, vector<vector<int>>(m, vector<int>(3, 0)));
    bool is_symmetric = true;
    
    for (int k = 0; k < q; ++k) {
        int i, j, t, c;
        cin >> i >> j >> t >> c;
        
        --i; --j; --t; // 将索引调整为0基
        image[i][j][t] = (image[i][j][t] + c) % 256;
        
        int mirror_j = m - j - 1; // 计算对称列位置

        // 更新对称状态
        if (image[i][j] != image[i][mirror_j]) {
            is_symmetric = false;
        } else {
            // 保持之前的对称状态
            is_symmetric = true;
            for (int x = 0; x < n; ++x) {
                for (int y = 0; y <= m / 2; ++y) {
                    if (image[x][y] != image[x][m - y - 1]) {
                        is_symmetric = false;
                        break;
                    }
                }
                if (!is_symmetric) break;
            }
        }
        
        cout << (is_symmetric ? "Yes" : "No") << endl;
    }
    return 0;
}
