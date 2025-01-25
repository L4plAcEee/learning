#include <iostream>
#include <stack>
#include <string>

using namespace std;

string matchBrackets(const string &s) {
    stack<char> stk; // 存储未匹配的左括号
    string result; // 用于构建结果字符串

    for (char c : s) {
        if (c == '(' || c == '[') {
            // 如果是左括号，直接加入结果并压入栈中
            result += c;
            stk.push(c);
        } else if (c == ')' || c == ']') {
            // 如果是右括号，检查栈顶是否有匹配的左括号
            if (!stk.empty()) {
                char top = stk.top();
                // 判断是否匹配
                if ((c == ')' && top == '(') || (c == ']' && top == '[')) {
                    // 配对成功，加入结果
                    result += c;
                    stk.pop(); // 移除栈顶的左括号
                } else {
                    // 配对失败，直接加入结果
                    result += c;
                }
            } else {
                // 栈为空，直接加入结果
                result += c;
            }
        }
    }

    // 处理未匹配的左括号
    while (!stk.empty()) {
        char top = stk.top();
        result += (top == '(') ? ')' : ']'; // 根据左括号添加相应的右括号
        stk.pop();
    }

    return result;
}

int main() {
    string s;
    cin >> s; // 输入字符串
    string matched = matchBrackets(s);
    cout << matched << endl; // 输出结果
    return 0;
}
