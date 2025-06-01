#include <bits/stdc++.h>
using namespace std;

// C++ 的 Lambda 表达式默认不能直接递归调用自身，因为它没有名称可供调用。
// function<void(size_t)> loop = [&](size_t times){
//     if (times == 1) return;
//     else loop(times - 1);
// };

// 不能在定义时用 [&] 捕获自身变量 loop，因为此时 loop 还未完全定义
// function<void(size_t, const function<void(size_t)>&)> loop = [&](size_t times, const function<void(size_t)>& func) {
//     if (times == 0) return;
//     func(times - 1); // 可以改成 func(total - times) 实现正序
//     loop(times - 1, func);
// };

int32_t main() {
    function<void(size_t, const function<void(size_t)>&)> loop;
    loop = [&loop](size_t times, const function<void(size_t)>& func) {
        if (times == 0) return;
        func(times - 1);
        loop(times - 1, func);
    };
    loop(5, [](size_t i) {
        cout << "第 " << i << " 次调用" << endl;
    });

    function<void(size_t, size_t, const function<void(size_t)>&)> loop2;
    loop2 = [&](size_t i, size_t times, const function<void(size_t)>& func) {
        if (i >= times) return;
        func(i);
        loop2(i + 1, times, func);
    };

    loop2(0, 5, [](size_t i) {
        cout << "第 " << i << " 次调用" << endl;
    });
}