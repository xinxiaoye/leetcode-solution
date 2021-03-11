/***
题目描述:给定一个数组，求这个数组中连续且等差的子数组一共有多少个。
dp数组记录以i位置结尾的等差数组的个数，最后求和
***/
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if(n<3) return 0;
        vector<int> dp(n, 0);
        for(int i=2; i<n; ++i){
            if(A[i]-A[i-1] == A[i-1]-A[i-2])
                dp[i] = dp[i-1] + 1;
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};