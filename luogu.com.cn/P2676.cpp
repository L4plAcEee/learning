#include <bits/stdc++.h>
using namespace std;
// B <= 2e9 + 7
int N, B;

void solve() {
    cin >> N >> B;
    vector<int> vec(N);
    for (auto &n : vec) cin >> n;
    sort(vec.begin(), vec.end());
    int cnt = 0;
    for (int i = N - 1; i >= 0; --i) {
        if (B <= 0) break;
        B -= vec[i];
        cnt++;
    }
    cout << cnt << '\n';
}

int32_t main() {
    solve();
    return 0;
}