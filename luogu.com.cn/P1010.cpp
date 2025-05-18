#include <bits/stdc++.h>
using namespace std;

string convert(int n) {
    if (n == 0) return "0";
    if (n == 1) return "2(0)";
    string res;

    for (int i = 30; i >= 0; --i) {
        if (n >= (1 << i)) {
            n -= 1 << i;
            if (i == 1) res += "+2";
            else res += "+2(" + convert(i) + ")";
        }
    }
    res.erase(0, 1);
    return res;
}

int main() {
    int n;
    cin >> n;
    cout << convert(n) << endl;
    return 0;
}