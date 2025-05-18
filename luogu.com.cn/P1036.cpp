#include <bits/stdc++.h>
using namespace std;

#define MAXN 21

int n = 0, k = 0;
int a[MAXN] = {0};

bool is_prime(long long num) {
    if (num < 2) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (long long n = 3; n * n <= num; n += 2) {
        if (num % n == 0) return false;
    }
    return true;
}

int dfs(int cnt, int idx, long long sum) {
    if (cnt == k) {
        return is_prime(sum) ? 1 : 0;        
    } else if (idx == n) {
        return 0;
    }
    return dfs(cnt + 1, idx + 1, sum + a[idx]) + dfs(cnt, idx + 1, sum);
}

int32_t main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << dfs(0, 0, 0) << '\n';
}