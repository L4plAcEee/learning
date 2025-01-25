#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// 计数排序算法
void counting_sort(vector<int>& vec) {
    int arr[1001] = {0};
    for(auto it : vec) {
        arr[it]++;
    }
    int index = 0;
    for(int i = 0; i < 1001; ++i) {
        while (arr[i] > 0) {
            vec[index++] = i;
            arr[i]--;
        }
    }
}

void test_counting_sort() {
    vector<int> vec = {10, 3, 7, 1, 1000, 500, 3, 7};
    counting_sort(vec);
    
    vector<int> expected = {1, 3, 3, 7, 7, 10, 500, 1000};
    assert(vec == expected);
}

int main() {
    test_counting_sort();
    cout << "所有测试用例均通过！" << endl;

    return 0;
}
