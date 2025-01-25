#include <vector>
#include <cmath>
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            if(nums[left] == val) {
                swap(nums[left], nums[right]);
                right--;
            }else {
                left++;
            }
        }
        return right + 1;
    }
};
// 双指针经典
int main() {
    int val;
    vector<int> vec = {0, 1, 2, 2, 3, 0, 4, 2};
    Solution sol;
    
    cout << "请输入要移除的值: ";
    cin >> val;
    
    int k = sol.removeElement(vec, val);
    vec.resize(k); // 只保留有效元素

    vector<int> ans = {0, 1, 3, 0, 4}; // 预期结果
    sort(vec.begin(), vec.end());
    sort(ans.begin(), ans.end());
    assert(ans == vec);
    
    cout << "评测通过" << endl;
    cout << "有效元素为: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
