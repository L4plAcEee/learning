#include <bits/stdc++.h>
using namespace std;

string s;
bool memo[101] = {false};

char get_another(char c) {
    if (c == '(') return ')';
    if (c == ')') return '(';
    if (c == '[') return ']';
    if (c == ']') return '[';
    return ' ';
}

int main() {
    cin >> s;
    stack<int> stk;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(' || s[i] == '[') {
            stk.push(i);
        } else {
            if (!stk.empty() && s[stk.top()] == get_another(s[i])) {
                stk.pop(); // 成功配对
            } else {
                memo[i] = true; // 无法配对的右括号
            }
        }
    }
    while (!stk.empty()) {
        memo[stk.top()] = true; // 未配对的左括号
        stk.pop();
    }
    string ans;
    for (int i = 0; i < s.length(); ++i) {
        if (memo[i]) {
            if (s[i] == '(') ans += "()";
            else if (s[i] == ')') ans += "()";
            else if (s[i] == '[') ans += "[]";
            else if (s[i] == ']') ans += "[]";
        } else {
            ans += s[i];
        }
    }
    cout << ans << '\n';
}