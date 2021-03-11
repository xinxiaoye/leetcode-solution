/***
题目描述：
    给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
    请你找出并返回 strs 的最大子集的大小，该子集中 最多 有 m 个 0 和 n 个 1 。
    如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。
题解：
    多维背包问题，两个限制（0和1的数量）
***/
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N = strs.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i = 1; i<=N; ++i){
            auto [num0, num1] = count(strs[i-1]); 
            for(int j = m; j >=num0 ; --j){     //逆向遍历，小于0，1数量的不考虑，因为连当前的0，1都不够。
                for(int k = n; k >= num1; --k){
                    dp[j][k] = max(dp[j][k], dp[j-num0][k-num1] + 1);
                }
            }
        }
        return dp[m][n];
    }

    pair<int, int> count(const string & s){
        int count0 = s.length(), count1 = 0; 
        for (const char & c: s) {
            if (c == '1') {
                ++count1;
                --count0; 
            }
        }
        return make_pair(count0, count1); }
};