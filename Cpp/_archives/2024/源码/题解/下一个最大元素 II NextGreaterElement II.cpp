#include <vector>
#include <stack>
#include <iostream>

class Solution {
public:
    std::vector<int> nextGreaterElements(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> answer(n, -1);  // 初始化为 -1
        std::stack<int> s;

        // 第一次遍历，从头到尾
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && nums[i] > nums[s.top()]) {
                answer[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
        }

        // 第二次遍历，从头到尾
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && nums[i] > nums[s.top()]) {
                answer[s.top()] = nums[i];
                s.pop();
            }
        }

        return answer;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {1, 2, 1};
    std::vector<int> result = solution.nextGreaterElements(nums);
    
    for (int num : result) {
        std::cout << num << " ";
    }
    
    return 0;
}
