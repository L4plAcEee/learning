#include <bits/stdc++.h>
using namespace std;

string expr;

int main() {
    cin >> expr;
    stack<int> stk;
    for (int i = 0; i < expr.length(); ++i) {
        int num = 0;
        if (expr[i] != '.' && expr[i] != '@') {
            if (isalnum(expr[i])) {
                num *= 10;
                num += expr[i] - '0';
            } else {
                int ans = 0;
                int op1 = stk.top();stk.pop();
                int op2 = stk.top();stk.pop();
                if (expr[i] == '+') {
                    ans = op2 + op1;
                } else if (expr[i] == '-') {
                    ans = op2 - op1;
                } else if (expr[i] == '*') {
                    ans = op2 * op1;
                } else if (expr[i] == '/') {
                    ans = op2 / op1;
                }
                stk.push(ans);
            }
        } else if (expr[i] == '.') {
            stk.push(num);
            num = 0;
        }
    }
    cout << stk.top() << '\n';
}