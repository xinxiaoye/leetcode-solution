/***
题目描述
    给定一个字符串和一个字符串集合，求是否存在一种分割方式，使得原字符串分割后的子字 符串都可以在集合内找到。
题解
    类似于完全平方数分割问题，这道题的分割条件由集合内的字符串决定，因此在考虑每个分 
    割位置时，需要遍历字符串集合，以确定当前位置是否可以成功分割。注意对于位置 0，需要初 始化值为真。
***/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int i=0; i<=n; i++){
            for(string & word :wordDict){
                int len = word.length();
                if(i>=len && s.substr(i-len, len) == word){
                    dp[i] = dp[i-len] || dp[i];
                }
            }
        }
        return dp[n];
    }
};