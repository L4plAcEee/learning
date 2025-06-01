#include <bits/stdc++.h>
using namespace std;

int A, B, C;
int group[3];
int used[10] = {0};
vector<string> res;

void f(int idx) {
    if (idx == 3) {
        if (group[0] * B == group[1] * A && group[1] * C == group[2] * B) {
            string ans;
            ans += to_string(group[0]) + " " + to_string(group[1]) + " " + to_string(group[2]);
            res.push_back(ans);
        }
        return;
    }
    
    for (int i = 100; i <= 999; ++i) {
        int d3 = i / 100;        
        int d2 = (i / 10) % 10;      
        int d1 = i % 10;       
        if (d1 * d2 * d3 == 0) continue;
        if (d1 == d2 || d2 == d3 || d1 == d3) continue;
        if (used[d1] ||  used[d2] || used[d3]) continue;
        used[d1] = 1;
        used[d2] = 1;
        used[d3] = 1;     
        group[idx] = i;
        f(idx + 1);
        used[d1] = 0;
        used[d2] = 0;
        used[d3] = 0;
    }
}

int32_t main() {
    cin >> A >> B >> C;
    f(0);
    if (res.empty()) cout << "No!!!" << '\n';
    else {
        for (auto ans : res) {
            cout << ans << '\n';
        }
    }

    return 0;
}