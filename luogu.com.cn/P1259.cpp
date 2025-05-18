#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << '\n';
int n;
string s;

void change(int from, int to) {
    swap(s[from], s[to]);
    swap(s[from + 1], s[to + 1]);
    cout << s << '\n';
}
 
void f(int idx) {
  if (idx == 8) {
        change(8, 3);
        change(3, 7);
        change(7, 1);
        change(1, 6);
        change(6, 0);
        return;
    }
    
    int half = idx / 2 - 1;
    change(half, idx);
    idx -= 2;
    change(half, idx);
    f(idx);
}

int32_t main() {
    cin >> n;
    s += string(n, 'o');
    s += string(n, '*');
    s += "--";
    cout << s << '\n';
    f(2 * n);
}