// 题目描述

// 给定一个整数数组 Array，请计算该数组在每个指定区间内元素的总和。

// 输入描述

// 第一行输入为整数数组 Array 的长度 n，接下来 n 行，每行一个整数，表示数组的元素。随后的输入为需要计算总和的区间，直至文件结束。

// 输出描述

// 输出每个指定区间内元素的总和。
#include <iostream>
#include <vector>
using namespace std;
// C++ 代码 面对大量数据 读取 输出操作，最好用scanf 和 printf，耗时会小很多：
int main() {
    int n, a, b;
    cin >> n;
    vector<int> vec(n);
    vector<int> p(n);
    int presum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &vec[i]);
        presum += vec[i];
        p[i] = presum;
    }
    while (~scanf("%d%d", &a, &b)) {
    /*
    scanf("%d%d", &a, &b)：该函数尝试读取两个整数并将它们存储到变量 a 和 b 中。
    如果成功读取到两个整数，
    返回值将是成功读取的参数个数（这里是 2）。
    ~ 操作符：这个按位取反操作符用于检查 scanf 的返回值。
    如果成功读取到两个整数，scanf 返回 2，取反后变为 -3，在条件判断中被视为 true；
    如果未能读取（如遇到文件结束或输入错误），返回值可能是 EOF（通常为 -1），取反后变为 0，此时条件判断为 false。
    */
        int sum;
        if (a == 0) sum = p[b];
        else sum = p[b] - p[a - 1];
        printf("%d\n", sum);
    }
}