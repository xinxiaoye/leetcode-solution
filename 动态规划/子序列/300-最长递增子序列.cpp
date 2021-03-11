/***
题目描述：
    给定一个未排序的整数数组，求最长的递增子序列。
题解：
    在本题中，dp[i] 可以表示以 i 结尾的、最长子序列长度。对于每一个位置 i，如果其之前的某 个位置 j 所对应的数字小于位置 i 所对应的数字，
    则我们可以获得一个以 i 结尾的、长度为 dp[j] + 1 的子序列。为了遍历所有情况，我们需要 i 和 j 进行两层循环，其时间复杂度为 O(n2)。
***/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int max_length = 0, n = nums.size();
        if (n < 1)  return n;
        vector<int> dp(n, 1);

        for(int i=0; i <n; ++i){
            for(int j=0; j<i; j++){
                if (nums[i] > nums[j]) 
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            max_length = max(max_length, dp[i]);
        }
        return max_length;
    }
};

//用dp数组存储长度为 i的递增数组的最后一个最小的值。
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp;

        dp.push_back(nums[0]);
        for(int i = 1; i < n; ++i){
            if(dp.back() < nums[i])
                dp.push_back(nums[i]);
            if(dp.back() > nums[i]){
                int mid, l = 0, r = dp.size()-1;
                // int ind;
                for(int num:dp)
                    cout << num <<endl;
                while(l != r){
                    mid = (l+r)/2;
                    if(dp[mid] < nums[i])
                        l = mid + 1;
                    else{
                        // ind = mid;
                        r = mid;
                    }
                    // cout << l << r << endl;
                }
                dp[l] = nums[i];
            }
        }
        return dp.size();
    }
};



