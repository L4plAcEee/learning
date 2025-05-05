#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = reduce(nums.begin(), nums.end(), 0);
        return (sum < target || ((target & 1) ^ (sum & 1)) == 1) ? 0 : subsets(nums, (target + sum) >> 1);
    }
    int subsets(vector<int> &nums, int t) {
        if (t < 0) return 0;
        vector<int> dp(t + 1, 0);
        dp[0] = 1;
        for (int num : nums) {
            for (int j = t; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }
        return dp[t];
    }

    int findTargetSumWays3(vector<int>& nums, int target) {
        int s = reduce(nums.begin(), nums.end(), 0);
        if (target < -s || target > s) {
            return 0;
        }
        int n = nums.size(), m = 2 * s + 1;
        vector<vector<int>> dp(n + 1, vector<int>(m, 0));
        dp[n][target + s] = 1;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = -s; j <= s; ++j) {
                if (j + nums[i] + s < m) {
                    dp[i][j + s] = dp[i + 1][j + nums[i] + s];
                }
                if (j - nums[i] + s >= 0) {
                    dp[i][j + s] += dp[i + 1][j - nums[i] + s];
                }
            }
        }
        return dp[0][s];
    }


    int findTargetSumWays2(vector<int>& nums, int target) {
        unordered_map<int, unordered_map<int, int>> dp;
        return f2(nums, target, 0, 0, dp);
    }
    int f2(vector<int>& nums, int target, int idx, int sum, unordered_map<int, unordered_map<int, int>>& dp) {
        if (idx == nums.size()) {
            return sum == target ? 1 : 0;
        }
        if (dp.count(idx) && dp[idx].count(sum)) {
            return dp[idx][sum];
        }
        int ans = f2(nums, target, idx + 1, sum + nums[idx], dp) 
                + f2(nums, target, idx + 1, sum - nums[idx], dp);
        dp[idx][sum] = ans;
        return ans;
    }

    int findTargetSumWays1(vector<int>& nums, int target) {
        return f1(nums, target, 0, 0);
    }
    int f1(vector<int> &nums, int target, int idx, int sum) {
        if (idx == nums.size()) {
            return sum == target ? 1 : 0;
        }
        return f1(nums, target, idx + 1, sum + nums[idx]) + f1(nums, target, idx + 1, sum - nums[idx]);
    }
};