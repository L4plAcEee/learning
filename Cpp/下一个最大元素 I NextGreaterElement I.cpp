#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> NGE;  // 存储每个 nums2 元素对应的下一个更大元素
        stack<int> s;

        // 从右到左遍历 nums2
        for (int i = nums2.size() - 1; i >= 0; --i) {
            // 维护单调递减栈
            while (!s.empty() && s.top() <= nums2[i]) {
                s.pop();  // 弹出所有比当前元素小的栈顶元素
            }

            // 如果栈为空，说明右侧没有比当前元素更大的元素
            NGE[nums2[i]] = s.empty() ? -1 : s.top();

            // 当前元素入栈
            s.push(nums2[i]);
        }

        // 构建结果数组
        vector<int> result;
        for (int num : nums1) {
            result.push_back(NGE[num]);  // 查询每个 nums1 元素的下一个更大元素
        }

        return result;
    }
};

// 测试函数
int main() {
    Solution sol;
    
    // 测试用例 1
    vector<int> nums1_1 = {4, 1, 2};
    vector<int> nums2_1 = {1, 3, 4, 2};
    vector<int> result1 = sol.nextGreaterElement(nums1_1, nums2_1);
    
    cout << "Test Case 1: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    // 测试用例 2
    vector<int> nums1_2 = {2, 4};
    vector<int> nums2_2 = {1, 2, 3, 4};
    vector<int> result2 = sol.nextGreaterElement(nums1_2, nums2_2);

    cout << "Test Case 2: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
