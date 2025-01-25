#include <vector>
#include <unordered_map>
#include <queue>
#include <cassert> // 用于 assert
#include <algorithm> // 用于 sort
#include <iostream>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    vector<int> res;
    for(int i = 0; i < nums.size(); ++i) {
        map[nums[i]]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
    for(auto it : map) {
        if(it.second == 0) continue;
        min_heap.push({it.second, it.first});
        if(min_heap.size() > k) {
            min_heap.pop();
        }
    }
    while(!min_heap.empty()) {
        res.push_back(min_heap.top().second);
        min_heap.pop();
    }
    return res;
}

// 测试 topKFrequent 函数
void test_topK() {

    // 测试用例 1
    std::vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    int k1 = 2;
    std::vector<int> result1 = topKFrequent(nums1, k1);
    std::vector<int> expected1 = {1, 2}; // 频率最高的两个元素
    std::sort(result1.begin(), result1.end());
    std::sort(expected1.begin(), expected1.end());
    assert(result1 == expected1); // 断言测试

    // 测试用例 2
    std::vector<int> nums2 = {1};
    int k2 = 1;
    std::vector<int> result2 = topKFrequent(nums2, k2);
    std::vector<int> expected2 = {1};
    assert(result2 == expected2);

    // 测试用例 3
    std::vector<int> nums3 = {1, 2, 3, 3, 4, 5, 6, 7, 8, 9, 10, 1, 1, 2, 2};
    int k3 = 3;
    std::vector<int> result3 = topKFrequent(nums3, k3);
    std::vector<int> expected3 = {1, 2, 3}; // 频率最高的三个元素
    std::sort(result3.begin(), result3.end());
    std::sort(expected3.begin(), expected3.end());
    // for(auto it : result3) {
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    // for(auto it : expected3) {
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    assert(result3 == expected3);

    // 测试用例 4
    std::vector<int> nums4 = {5, 3, 1, 2, 4, 5, 5, 3, 3, 2, 1};
    int k4 = 2;
    std::vector<int> result4 = topKFrequent(nums4, k4);
    std::vector<int> expected4 = {5, 3}; // 频率最高的两个元素
    std::sort(result4.begin(), result4.end());
    std::sort(expected4.begin(), expected4.end());
    assert(result4 == expected4);

    // 测试用例 5
    std::vector<int> nums5 = {};
    int k5 = 0;
    std::vector<int> result5 = topKFrequent(nums5, k5);
    std::vector<int> expected5 = {}; // 空输入
    assert(result5 == expected5);

    std::cout << "All tests passed!" << std::endl; // 所有测试通过的提示
}

int main() {
    test_topK();
}