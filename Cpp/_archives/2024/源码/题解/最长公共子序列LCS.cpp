#include <iostream>
#include <vector>
#include <string>

using namespace std;
//在只提供删除操作下的最小编辑距离 实际上是LCS问题.
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        
        // 创建 DP 表，大小为 (len1 + 1) x (len2 + 1)
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        
        // 填充 DP 表
        for(int i = 1; i <= len1; ++i) {
            for(int j = 1; j <= len2; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1; // 字符相同
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // 字符不同
                }
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

        int LCS = dp[len1][len2]; // 最长公共子序列长度
        // 返回最小删除步数
        return (len1 - LCS) + (len2 - LCS);
    }
};

int main() {
    Solution solution;
    string word1 = "intention";
    string word2 = "execution";
    
    int min_steps = solution.minDistance(word1, word2);
    cout << "最小删除步骤: " << min_steps << endl;
    
    return 0;
}
