#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> operations(n); // 记录所有的交换操作
    for (int i = 0; i < n; i++) {
        cin >> operations[i].first >> operations[i].second; // 读入交换操作
    }

    for (int query = 0; query < m; query++) {
        int L, R;
        cin >> L >> R; // 输入查询区间
        L--; R--; // 0-based index

        vector<int> cards = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // 初始牌组
        vector<int> diff(n + 1, 0); // 差分数组

        // 标记查询区间
        diff[L]++;
        if (R + 1 < n) diff[R + 1]--;

        // 打印差分数组的状态
        cout << "差分数组: ";
        for (int i = 0; i < n; i++) {
            cout << diff[i] << " ";
        }
        cout << endl;

        // 处理操作
        int active_operations = 0; // 累加活动的操作
        for (int i = 0; i < n; i++) {
            active_operations += diff[i]; // 累加操作
            if (active_operations > 0) {
                // 执行操作
                auto [x, y] = operations[i]; // 获取当前操作
                swap(cards[x], cards[y]); // 交换卡牌
            }
        }

        // 打印当前牌组状态
        cout << "执行完操作后的牌组: ";
        for (int i = 0; i < 10; i++) {
            cout << cards[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
