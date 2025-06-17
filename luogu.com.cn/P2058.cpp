#include <bits/stdc++.h>
using namespace std;

const int DAY_TIME = 86400;
const int MAXK = 3e5 + 1;
const int MAXN = 1e5 + 1;

int n;
int passage[MAXK] = {0};  // 国籍计数
int diff_cnt = 0;         // 当前不重复的国家数

// 每艘船的数据：到达时间 + 乘客国籍列表
struct Ship {
    int time;
    vector<int> passengers;
};

queue<Ship> q;

void clean(int current_time) {
    // 将超过24小时的船只弹出队列
    while (!q.empty() && q.front().time <= current_time - DAY_TIME) {
        for (int x : q.front().passengers) {
            passage[x]--;
            if (passage[x] == 0) {
                diff_cnt--;
            }
        }
        q.pop();
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int t, k, x;
        cin >> t >> k;
        vector<int> temp;
        for (int j = 0; j < k; ++j) {
            cin >> x;
            temp.push_back(x);
            if (passage[x] == 0) {
                diff_cnt++;
            }
            passage[x]++;
        }
        q.push({t, temp});
        clean(t);  // 清除超出24小时的船只
        cout << diff_cnt << "\n";
    }
    return 0;
}
