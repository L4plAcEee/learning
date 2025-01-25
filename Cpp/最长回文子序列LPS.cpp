#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for(int j = 0; j < s.size(); ++j) {
            for(int i = j; i >= 0; --i) {
                if(s[i] == s[j]) {
                    if(j - i < 2) {
                        dp[i][j] = j - i + 1;
                    }
                    else {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    }
                }else {
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                }
            }
        }
        
        // 打印 DP 数组
        cout << "DP Array:\n";
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < s.size(); ++j) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        return dp[0][s.size() - 1];
    }
};

int main() {
    Solution solution;
    string word = "bbbab";
    
    int min_steps = solution.longestPalindromeSubseq(word);
    cout << "LPS: " << min_steps << endl;
    
    return 0;
}
