#include <bits/stdc++.h>
using namespace std;
// https://www.luogu.com.cn/problem/P1563

// 朝内往左数是往数组左边走 那么朝内往右数就是往数组右边走：即 朝内（0） 时 0 : <--- ，1 : --->
// 朝外往右数是往数组左边走 那么朝外往左数就是往数组左边走：即 朝内（0） 时 0 : ---> ，1 : <---
void solve(vector<string> &toys, vector<int> &face, int n, int m) {
    int cur = 0;
    while (m--) {
        // 0，表示向左数  1，表示向右数 
        int dir, num;
        cin >> dir >> num;
        if (dir == 1) {
            if (face[cur] == 1) {
                cur = (cur + n - num) % n;
            } else {
                cur = (cur + num) % n;
            }
        } else {
            if (face[cur] == 1) {
                cur = (cur + num) % n;
            } else {
                cur = (cur + n - num) % n;
            }
        }
    }
    cout << toys[cur];
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<string> toys(n);
    vector<int> face(n); // 0 朝内， 1 朝外

    for (int i = 0; i < n; ++i) {
        cin >> face[i] >> toys[i];
    }
    solve(toys, face, n, m);

    return 0;
}