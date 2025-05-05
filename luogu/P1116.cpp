#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;
int N, a[MAXN], tmp[MAXN];
long long cnt = 0;

void merge_sort(int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else {
            tmp[k++] = a[j++];
            cnt += mid - i + 1; // 关键：逆序对增加
        }
    }
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];
    for (int p = l; p <= r; ++p) a[p] = tmp[p];
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> a[i];
    merge_sort(0, N - 1);
    cout << cnt << '\n';
}

int32_t main() {
    solve();
}
