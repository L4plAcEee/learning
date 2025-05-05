#include <bits/stdc++.h>
using namespace std;
using u64 = unsigned long long;
using i64 = long long;
using f64 = double;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define ppb() pop_back()

// n <= 999, m <= 2e6
int n, m;
int arr[1000] = {0};
// vector<int> vec;

void solve() {
    cin >> n >> m;
    for (int i = 0, temp = 0; i < m; ++i) {
        cin >> temp;
        arr[temp]++;
    }
    for (int i = 0; i < 1000; ++i) {
        while (arr[i]--) {
            cout << i << ' ';
        }
    }
}

int main() {
    solve();
}