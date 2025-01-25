#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> dailyTemperatures(const vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> answer(n, 0);  // 初始化结果数组，默认值为 0
    stack<int> s;  // 用来存储索引的栈

    // 遍历温度数组
    for (int i = 0; i < n; ++i) {
        // 打印当前栈的内容
        cout << "当前栈 (索引 -> 温度): ";
        stack<int> tempStack = s;
        while (!tempStack.empty()) {
            int idx = tempStack.top();
            tempStack.pop();
            cout << idx << " -> " << temperatures[idx] << " ";
        }
        cout << endl;

        // 当当前温度比栈顶所对应的温度高时，说明找到了下一个更高温度
        while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
            int idx = s.top();
            s.pop();  // 出栈
            answer[idx] = i - idx;  // 计算相隔天数
        }
        s.push(i);  // 当前天的索引入栈
    }

    return answer;
}

int main() {
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = dailyTemperatures(temperatures);

    // 打印结果
    cout << "结果: ";
    for (int r : result) {
        cout << r << " ";
    }
    cout << endl;

    return 0;
}
