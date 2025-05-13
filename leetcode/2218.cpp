#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int items = piles.size() + 1, capacity = k + 1;
        vector<vector<long long>> dp(items, vector<long long>(capacity, 0));

        for (int i = 1; i <= piles.size(); ++i) {
            for (int j = 0; j <= k; ++j) {
                long long res1 = dp[i - 1][j];
                long long res2 = 0;
                int sum = 0;
                for (int coin = 0; coin < piles[i - 1].size() && coin + 1 <= j; ++coin) {
                    sum += piles[i - 1][coin];
                    res2 = max(res2, dp[i - 1][j - (coin + 1)] + sum);
                }
                dp[i][j] = max(res1, res2);
            }
        }
        return dp[piles.size()][k];
    }
};