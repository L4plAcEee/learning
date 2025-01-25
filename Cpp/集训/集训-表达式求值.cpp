#include <iostream>
#include <string>

using namespace std;

int main() {
    string expression;
    cin >> expression; // 读取表达式

    long long result = 0; // 总结果
    long long currentNumber = 0; // 当前数字
    char currentOp = '+'; // 当前操作符，初始化为加法

    for (size_t i = 0; i < expression.size(); ++i) {
        char c = expression[i];
        
        // 如果是数字，累积成当前数字
        if (isdigit(c)) {
            currentNumber = currentNumber * 10 + (c - '0');
        }
        
        // 如果是操作符，或者到了表达式的末尾
        if (c == '+' || c == '*' || i == expression.size() - 1) {
            if (currentOp == '*') {
                result *= currentNumber; // 处理乘法
            } else if (currentOp == '+') {
                result += currentNumber; // 处理加法
            }

            // 更新当前操作符和重置当前数字
            currentOp = c;
            currentNumber = 0; // 重置当前数字
        }
    }

    // 处理最后一个数字
    if (currentOp == '*') {
        result *= currentNumber;
    } else if (currentOp == '+') {
        result += currentNumber;
    }

    // 将结果转换为字符串，处理最后四位
    string resultStr = to_string(result);
    if (resultStr.length() > 4) {
        resultStr = resultStr.substr(resultStr.length() - 4);
    }

    // 去除前导零
    while (resultStr.length() > 1 && resultStr[0] == '0') {
        resultStr.erase(resultStr.begin());
    }

    cout << resultStr << endl; // 输出结果

    return 0;
}
