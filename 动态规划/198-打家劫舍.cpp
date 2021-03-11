/***
    状态转移，前一家偷 或 不偷 取最大
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)  return 0;

        vector<int> dp(n+1, 0);

        dp[1] = nums[0];
        for(int i=2; i<=n; ++i){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
        }
        return dp[n];
    }
};
//空间压缩
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)  return 0;

        int pre1=0, cur = 0;
        for(int i=0; i<n; ++i){
            int temp = cur;
            cur = max(cur, pre1 + nums[i]);
            pre1 = temp;
        }
        return cur;
    }
};