#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cout << #x << " : " << x << '\n';

struct farmer {
    int milk;
    int unit;
};

int32_t main() {
    int n, m;
    cin >> m >> n;
    vector<farmer> a(n);
    for (int i = 0; i < n ; ++i){
        cin >> a[i].unit >> a[i].milk;
    }
    sort(a.begin(), a.end(), [](farmer &a, farmer &b){
        return a.unit < b.unit;
    });
    int total_cost = 0, total_requirement = 0;
    for (int i = 0; i < n && total_requirement < m; ++i) {
        int cur_requirement = min(a[i].milk, m - total_requirement);
        total_cost += cur_requirement * a[i].unit;
        total_requirement += cur_requirement;
        // dbg(a[i].milk);
        // dbg(a[i].unit);
        // dbg(total_cost);
        // dbg(total_requirement);
    }
    cout << total_cost << '\n';
}