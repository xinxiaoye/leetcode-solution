/***
题目描述：
    给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
题解：
    本题等价于 0-1 背包问题，设所有数字和为 sum，我们的目标是选取一部分物品，使得它们 的总和为 sum/2。
    这道题不需要考虑价值，因此我们只需要通过一个布尔值矩阵来表示状态转移 矩阵。注意边界条件的处理。
**/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums)
            sum += num;
        if(sum % 2 ==1 )    return false;
        int target = sum / 2, n = nums.size();

        vector<vector<bool>> dp(n + 1,vector<bool>(target + 1, false));
        for(int i = 0; i <= n; ++i)
            dp[i][0] = true;
        for(int i = 1; i <= n; ++i){
            for(int j= nums[i-1]; j <= target; ++j){ //从nums[i-1]开始，因为 target不会小于当前位置（i-1）的值
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }
        return dp[n][target];
    }
};

//空间压缩
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums)
            sum += num;
        if(sum % 2 ==1 )    return false;
        int target = sum / 2, n = nums.size();

        vector<vector<bool>> dp(target + 1, false));
        dp[0] = true;
        for(int i = 1; i <= n; ++i){
            for(int j= target; j >=num[i-1]; --j){ //逆向遍历，因为两个都是上一行
                dp[j] = dp[j] || dp[j-nums[i-1]];
            }
        }
        return [target];
    }
};