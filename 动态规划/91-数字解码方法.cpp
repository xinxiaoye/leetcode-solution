/***
题目描述
    已知字母 A-Z 可以表示成数字 1-26。给定一个数字串，求有多少种不同的字符串等价于这个 数字串。
题解
    这是一道很经典的动态规划题，难度不大但是十分考验耐心。
    这是因为只有 1-26 可以表示 字母，因此对于一些特殊情况，
    比如数字 0 或者当相邻两数字大于 26 时，需要有不同的状态转 移方程，详见如下代码。
***/


class Solution {
public:
    int numDecodings(string s) {
        if(s.length() == 0) return 0;
        if(s.length() == 1) return s[0] == '0' ? 0 : 1;
        int n = s.length();

        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 :1;
        for(int i=2; i<=n; ++i){
            if(s[i-1] != '0')
                dp[i] += dp[i-1];
            if(s[i-2] == '1' || (s[i-2]) == '2' && s[i-1] <= '6')
                dp[i] += dp[i-2];
        }
        return dp[n];
    }
};