#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, r;
    cin >> n >> m >> r;
    vector<vector<bool>> grid(n, vector<bool>(n, false));
    int count = 0;

    while (m--) {
        int x, y;
        cin >> x >> y;
        int up_board = (y - 1) - r >= 0 ? (y - 1) - r : 0;
        int down_board = (y - 1) + r < n ? (y - 1) + r : n - 1;
        int left_board = (x - 1) - r >= 0 ? (x - 1) - r : 0;
        int right_board = (x - 1) + r < n ? (x - 1) + r : n - 1;

        for (int i = up_board; i <= down_board; ++i) {
            for (int j = left_board; j <= right_board; ++j) {
                if ((i - (y - 1)) * (i - (y - 1)) + (j - (x - 1)) * (j - (x - 1)) <= r * r) {
                    if (!grid[i][j]) count++;
                    grid[i][j] = true;
                }
            }
        }
    }
    cout << count << endl;
}
