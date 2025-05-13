#include <bits/stdc++.h>
using namespace std;

#define MAXN 1001
#define MAXM 1001
#define MAXK 101

int m, n, k = 0;
int w[MAXN], v[MAXN], nxt[MAXN], head[MAXK], dp[MAXK][MAXM];

int solve() {
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= m; ++j) {
            int res1 = dp[i - 1][j];
            int res2 = 0;
            int cur = head[i];
            while (cur) {
                if (j - w[cur] >= 0) 
                    res2 = std::max(res2, dp[i - 1][j - w[cur]] + v[cur]);
                cur = nxt[cur];
            }
            dp[i][j] = std::max(res1, res2);
        }
    }
    return dp[k][m];
}

int32_t main() {
    memset(w, 0, sizeof(w));
    memset(v, 0, sizeof(v));
    memset(nxt, 0, sizeof(nxt));
    memset(dp, 0, sizeof(dp));
    memset(head, 0, sizeof(head));
    
    cin >> m >> n;
    
    for (int i = 1; i <= n; ++i) {
        int group;
        cin >> w[i] >> v[i] >> group;
        
        int temp = head[group];
        head[group] = i;
        nxt[i] = temp;
        
        k = max(k, group);
    }
    
    cout << solve() << '\n';
    
    return 0;
}