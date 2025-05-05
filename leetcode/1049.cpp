#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = reduce(stones.begin(), stones.end(), 0);
        int n = near(stones, sum/2);
        return sum - n - n;
    }
    int near(vector<int> &nums, int t) {
        vector<int> dp(t + 1, 0);
        for (auto &num : nums) {
            for (int j = t; j >= num; j--) {
                // 直接是空间压缩的版本
                dp[j] = std::max(dp[j], dp[j - num] + num);
            }
        }
        return dp[t];
    }
};