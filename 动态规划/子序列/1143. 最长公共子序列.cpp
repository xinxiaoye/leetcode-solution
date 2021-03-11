/***
题目描述：
    给定两个字符串，求它们最长的公共子序列长度。
题解：
    在本题中，我们可以建立一个二维数组 dp，其中 dp[i][j] 表示到第
    一个字符串位置 i 为止、到 第二个字符串位置 j 为止、最长的公共子序列长度。
    这样一来我们就可以很方便地分情况讨论这 两个位置对应的字母相同与不同的情况了。
***/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[0][0] = 0;
        for(int i = 1; i<=m; ++i)
            for(int j=1; j<=n; ++j){
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        return dp[m][n];
    }
};