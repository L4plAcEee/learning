#include <bits/stdc++.h>
using namespace std;
const int MAXM = 100000 + 5;
bool dp[MAXM];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while ( (cin >> n >> m) && (n || m) ){
        vector<int> A(n), C(n);
        for(int i = 0; i < n; i++) cin >> A[i];
        for(int i = 0; i < n; i++) cin >> C[i];

        fill(dp, dp + m + 1, false);
        dp[0] = true;

        for(int i = 0; i < n; i++){
            int v = A[i], cnt = C[i];
            // 0-1 背包
            if (cnt == 1) {
                for(int j = m; j >= v; j--){
                    if (dp[j-v]) dp[j] = true;
                }
            }
            // 完全背包（当总量足以视为无限时）
            else if ((long long)v * cnt >= m) {
                for(int j = v; j <= m; j++){
                    if (dp[j-v]) dp[j] = true;
                }
            }
            // 多重背包（单调队列优化）
            else {
                for(int mod = 0; mod < v; mod++){
                    deque<int> q;
                    // k 为“步数索引”，对应金额 j = mod + k*v
                    for(int k = 0, j = mod; j <= m; k++, j += v){
                        // —— 先把过期的 k 弹出 —— 
                        while (!q.empty() && k - q.front() > cnt) {
                            q.pop_front();
                        }
                        if (dp[j]) {
                            // 如果本来就能凑出，就把它当作新来源入队
                            q.push_back(k);
                        } 
                        else {
                            // 否则只要队里还有可用来源，就能凑出
                            if (!q.empty()) {
                                dp[j] = true;
                            }
                        }
                    }
                }
            }
        }

        int ans = 0;
        for(int i = 1; i <= m; i++){
            if (dp[i]) ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}
