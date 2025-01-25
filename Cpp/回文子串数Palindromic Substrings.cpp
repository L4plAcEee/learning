#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    int countSubstrings(std::string s) {
        int count = 0;
        int n = s.size();
        std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));
        
        for (int j = 0; j < n; ++j) {  // j 从0到n-1
            for (int i = j; i >= 0; --i) {  // i 从j到0
                if (s[i] == s[j]) {
                    if (j - i < 2) {  // j - i < 2 表示长度为1或2
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];  // 中间部分是否回文
                    }
                    if (dp[i][j]) count++;  // 如果是回文，增加计数
                }
            }
        }
        
        printDP(dp);  // 打印 dp 数组
        return count;
    }

private:
    void printDP(const std::vector<std::vector<bool>>& dp) {
        int n = dp.size();
        std::cout << "dp 数组:\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cout << (dp[i][j] ? "1 " : "0 ");  // 1 表示回文，0 表示非回文
            }
            std::cout << "\n";
        }
    }
};

// 示例代码，用于测试
int main() {
    Solution solution;
    std::string input = "abc";  // 你可以在这里更改输入
    int result = solution.countSubstrings(input);
    std::cout << "回文子字符串的数量: " << result << std::endl;  // 输出结果
    return 0;
}
