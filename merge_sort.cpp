#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        return _merge_sort(nums, 0, nums.size() - 1);
    }
    
    vector<int> _merge_sort(vector<int>& nums, int left, int right) {
        if (left == right) {
            return vector<int>{nums[left]};
        }
        
        int mid = left + (right - left) / 2;
        vector<int> left_vector = _merge_sort(nums, left, mid);
        vector<int> right_vector = _merge_sort(nums, mid + 1, right);
        
        return _merge(left_vector, right_vector);
    }
    
    vector<int> _merge(vector<int> left, vector<int> right) {
        vector<int> ret(left.size() + right.size());
        int i = 0, j = 0, k = 0;
        
        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) {
                ret[k++] = left[i++];
            } else {
                ret[k++] = right[j++];
            }
        }
        
        while (i < left.size()) {
            ret[k++] = left[i++];
        }
        
        while (j < right.size()) {
            ret[k++] = right[j++];
        }
        
        return ret;
    }
};

int main() {
    int N;
    cin >> N;
    
    vector<int> test1(N);
    for(int n = 0; n < N; ++n) {
        cin >> test1[n];
    }
    
    Solution solution;
    vector<int> sorted = solution.sortArray(test1);
    
    for(auto it : sorted) {
        cout << it << " ";
    }
    cout << endl;
    
    return 0;
}