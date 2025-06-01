#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int MAXA = 1e4 + 5;
int n, a[MAXN], cnt[MAXA] = {0};

int C (int x, int k) {
    return (k == 1 ? x : x * (x - 1) / 2) % MOD;
}

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    int max_a = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        max_a = max(a[i], max_a);
        cnt[a[i]]++;
    }
    for (int i = 2; i <= max_a; ++i) {
        if (cnt[i] >= 2) {
            int times = C(cnt[i], 2) % MOD;
            for (int j = 1; j <= i / 2; ++j) {
                if (j != i - j && cnt[j] >= 1 && cnt[i - j] >= 1) //用来合成的木棒长度不等 
                    ans += times * C(cnt[j], 1) * C(cnt[i - j], 1) % MOD;
                if (j == i - j && cnt[j] >= 2) //用来合成的木棒长度相等 
                    ans += times * C(cnt[j], 2) % MOD;
                ans %= MOD;
            }
        }
    }
    cout << ans << '\n';
    
}