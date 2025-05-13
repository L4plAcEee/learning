#include <bits/stdc++.h>
using namespace std;

#define i64 long long
string s;
i64 N;

i64 solve(i64 idx, i64 len) {
    return (idx <= s.length()) ? idx : ((idx == len / 2 + 1) ? solve(len / 2, len / 2) : ((idx > len / 2 + 1) ? solve(idx - len / 2 - 1, len / 2) : solve(idx, len / 2)));
}

int main() {
    cin >> s >> N;
    i64 len = s.length();
    while (len < N) len <<= 1;

    cout << s[solve(N, len) - 1] << '\n';
}
