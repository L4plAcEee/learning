#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        for(int i = 0; i <= len1; ++i) {
            dp[i][0] = i; // 删除所有字符
        }
        for(int j = 0; j <= len2; ++j) {
            dp[0][j] = j; // 删除所有字符
        }
        for(int i = 1; i <= len1; ++i) {
            for(int j = 1; j <= len2; ++j) {
                dp[i][j] = word1[i - 1] == word2[j - 1] ? dp[i - 1][j - 1] : 
                min({dp[i - 1][j] + 1, dp[i - 1][j - 1] + 1, dp[i][j - 1] + 1});
            }
        }

        // 打印 DP 数组
        cout << "DP Array:\n";
        for (int i = 0; i <= len1; ++i) {
            for (int j = 0; j <= len2; ++j) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        // 返回最小编辑距离
        return dp[len1][len2];
    }
};

int main() {
    Solution solution;
    string word1 = "intention";
    string word2 = "execution";
    
    int min_steps = solution.minDistance(word1, word2);
    cout << "最小编辑步骤: " << min_steps << endl;
    
    return 0;
}
