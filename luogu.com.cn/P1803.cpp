#include <bits/stdc++.h>
using namespace std;

struct Range {
    int left;
    int right;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Range> r(n);
    for (int i = 0; i < n; ++i) {
        cin >> r[i].left >> r[i].right;
    }
    // 按照结束时间升序排序
    sort(r.begin(), r.end(), [](const Range &a, const Range &b) {
        if (a.right == b.right) 
            return a.left < b.left;  // 结束时间相同，次要按开始时间升序
        return a.right < b.right;
    });

    int cnt = 0;
    int last_end = -1;  // 上一次选择的比赛结束时间，初始设为 -1（或更小都行）

    for (int i = 0; i < n; ++i) {
        if (r[i].left >= last_end) {
            // 可以选择这场比赛
            cnt++;
            last_end = r[i].right;
        }
    }

    cout << cnt << "\n";
    return 0;
}
