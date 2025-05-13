#include<bits/stdc++.h>
using namespace std;

#define i64 long long

int n;
vector<int> path;
vector<int> path2;

unordered_map<int, unordered_map<int, int>> memo;

i64 dfs() {
    if (path.back() == 1) 
        return 1;
    
    i64 ret = 1;
    for (int i = 1; i <= path.back() / 2; ++i) {
        path.push_back(i);
        ret += dfs();
        path.pop_back();
    }
    return ret;
}

i64 memorize_dfs() {
    i64 ret = 1;
    if (path2.back() == 1)
        return ret;
    if (memo.count(path2.size()) && memo[path2.size()].count(path2.back()))
        return memo[path2.size()][path2.back()];
    for (int i = 1; i <= path2.back() / 2; ++i) {
        path2.push_back(i);
        ret += memorize_dfs();
        path2.pop_back();
    }
    memo[path2.size()][path2.back()] = ret;
    return ret;
}

void solve1() {
    path.push_back(n);
    cout << dfs() << '\n';
}

void solve2() {
    path2.push_back(n);
    cout << memorize_dfs() << '\n';
}

int32_t main() {
    cin >> n;
    // solve1();
    solve2();
}