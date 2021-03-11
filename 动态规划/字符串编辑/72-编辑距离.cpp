/***
题目描述
    给定一个字母 A，已知你可以每次选择复制全部字符，或者粘贴之前复制的字符，求最少需 要几次操作可以把字符串延展到指定长度。
题解
    类似于题目 1143，我们使用一个二维数组 dp[i][j]，表示将第一个字符串到位置 i 为止，和第 二个字符串到位置 j 为止，最多需要几步编辑。
    当第 i 位和第 j 位对应的字符相同时，dp[i][j] 等 于 dp[i-1][j-1];
    当二者对应的字符不同时，
    修改的消耗是 dp[i-1][j-1]+1，
    插入 i 位置/删除 j 位置 的消耗是 dp[i][j-1] + 1，
    插入 j 位置/删除 i 位置的消耗是 dp[i-1][j] + 1。
***/
int minDistance(string word1, string word2) {
    int m = word1.length(), n = word2.length(); 
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); 
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else {
                dp[i][j] = min(
                    dp[i-1][j-1] + ((word1[i-1] == word2[j-1])? 0: 1), 
                    min(dp[i-1][j] + 1, dp[i][j-1] + 1));
            } 
        }
    }
    return dp[m][n];
}