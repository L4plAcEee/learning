#include <bits/stdc++.h>
using namespace std;

struct apple {
    int cost;
    int height;
};

int32_t main() {
    int n, s, a, b;
    cin >> n >> s >> a >> b;
    vector<apple> apples(n);
    for (int i = 0; i < n; ++i) {
        cin >> apples[i].height >> apples[i].cost;
    }
    sort(apples.begin(), apples.end(), [](auto &a, auto &b){
        return a.cost < b.cost;
    });
    int cnt = 0;
    for (int i = 0, cost_s = 0; i < n; ++i) {
        if ((apples[i].height <= a + b) && (cost_s + apples[i].cost <= s)) {
            cnt++;
            cost_s += apples[i].cost;
            // cout << "select: " << apples[i].height << " : " << apples[i].cost << '\n'; 
        }
    }
    cout << cnt << '\n';
}