#include <functional>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 定义一个纯加法函数
function<int(int, int)> add = [](int a, int b) {
    return a + b;
};

// 定义一个高阶函数：将两个整数加起来再加上一个偏移值（偏移值由外部闭包捕获）
function<function<int(int, int)>(int)> makeAdderWithOffset = [](int offset) {
    return [=](int a, int b) {
        return a + b + offset;
    };
};

// 定义 map 函数：将函数作用于 vector 上的所有元素
function<vector<int>(vector<int>, function<int(int)>)> map = [](vector<int> v, function<int(int)> f) {
    vector<int> result;
    result.reserve(v.size());
    for (int x : v) {
        result.push_back(f(x));
    }
    return result;
};

int main() {
    // 构造加偏移函数
    auto addWithOffset5 = makeAdderWithOffset(5);

    // 调用纯函数
    int result = addWithOffset5(2, 3);  // 2 + 3 + 5 = 10
    
    cout << result << '\n';
    
    // 创建输入数据
    vector<int> data = {1, 2, 3, 4, 5};

    // 使用 map 应用一个 lambda（平方函数）
    auto squared = map(data, [](int x) { return x * x; });


    return 0;
}
