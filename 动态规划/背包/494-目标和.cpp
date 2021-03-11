/***
题目描述：
    给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。
    返回可以使最终数组和为目标数 S 的所有添加符号的方法数。
题解：
    1.  正+负 = sum
        正-负 = S   
        ===>  正 = （S+sum）/2
        和416类似，背包
    
***/

/***
题解：
    2.  整个表格区域应该是分为三部分：-/0/+。那么对应的表格的每一行的长度t就可以表示为：t=(sum*2)+1，
    其中一个sum表示nums中执行全部执行加/减能达到的数，而加的1显然是中间的0.：
    这道题有个坑的地方，就是nums[0]可能等于0，这样初始化dp数组第一行的时候很可能踩坑，
    因为如果nums[0]==0那么dp[0][sum]需要初始化为2，因为加减0都得0。具体代码如下：
***/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0, n = nums.size();;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        // 绝对值范围超过了sum的绝对值范围则无法得到
        if (abs(S) > abs(sum)) return 0;

        vector<vector<int>> dp(n, vector<int>(2*sum+1, 0));
        if (nums[0] == 0) {
            dp[0][sum] = 2;
        } else {
            dp[0][sum + nums[0]] = 1;
            dp[0][sum - nums[0]] = 1;
        }
        for(int i = 1; i < n; ++i){
            int num = nums[i];
            for(int j = 0; j <= 2*sum; ++j){
                if(j - num>=0)
                    dp[i][j] += dp[i-1][j-num];
                if(j+num<=2*sum)
                    dp[i][j] += dp[i-1][j+num];
                // cout << i << j << dp[i][j] << endl;
            }
        }
        return dp[n-1][sum + S];
    }
};