#include <bits/stdc++.h>
using namespace std;

int main() {
    string n;
    int k;
    cin >> n >> k;
    
    // 方法1：逐个删除（简单易懂）
    string result = n;
    for (int times = 0; times < k; times++) {
        int pos = -1;
        for (int i = 0; i < result.length() - 1; i++) {
            if (result[i] > result[i + 1]) {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            pos = result.length() - 1;
        }
        result.erase(pos, 1);
    }
    
    // 处理前导零
    int start = 0;
    while (start < result.length() && result[start] == '0') {
        start++;
    }
    
    if (start == result.length()) {
        cout << "0" << endl;
    } else {
        cout << result.substr(start) << endl;
    }
    
    return 0;
}

/* 
// 方法2：使用栈优化（更高效）
#include <bits/stdc++.h>
using namespace std;

int main() {
    string n;
    int k;
    cin >> n >> k;
    
    string stack;
    int toRemove = k;
    
    for (char digit : n) {
        // 当栈不为空，还需要删除数字，且栈顶比当前数字大时
        while (!stack.empty() && toRemove > 0 && stack.back() > digit) {
            stack.pop_back();
            toRemove--;
        }
        stack.push_back(digit);
    }
    
    // 如果还需要删除数字，从末尾删除
    while (toRemove > 0) {
        stack.pop_back();
        toRemove--;
    }
    
    // 处理前导零
    int start = 0;
    while (start < stack.length() && stack[start] == '0') {
        start++;
    }
    
    if (start == stack.length()) {
        cout << "0" << endl;
    } else {
        cout << stack.substr(start) << endl;
    }
    
    return 0;
}
*/