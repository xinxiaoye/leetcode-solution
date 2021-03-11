/***
题目描述: 给定一个二维的 0-1 矩阵，求全由 1 构成的最大正方形面积。
取左上三个最小的正方形值 + 1
***/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0; 
        }
        int m = matrix.size(), n = matrix[0].size();

        int max_side = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n+1, 0));
        for(int i = 1; i<=m; ++i){
            for(int j=1; j<=n; ++j){
                if(matrix[i-1][j-1] == '1'){
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
                }
                max_side = max(max_side, dp[i][j]);
            }
        }
        return max_side*max_side;
    }
};