/***
题目描述：
    0-1背包：

     N 个物品和容量为 W 的背包，每个物品都有 自己的体积 w 和价值 v，
     求拿哪些物品可以使得背包所装下物品的总价值最大。如果限定每种物 品只能选择 0 个或 1 个，则问题称为 0-1 背包问题
题解：
    我们可以定义一个二维数组 dp 存储最大价值，其中 dp[i][j] 表示前 i 件物品体积不超过 j 的情况下能达到的最大价值
***/
int knapsack(vector<int> weights, vector<int> values, int N, int W){
    vector<vector<int>> dp(N+1, vector<int>(W+1, 0));

    for(int i=1; i<=N; ++i){
        int w = weights[i-1], v = values[i];
        for(int j=1; j<=W; ++j){
            if(j >= w)
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w] + v);
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[N][W]
}

//压缩空间
/*在考虑物品 i 时变成 dp[j] = max(dp[j], dp[j-w] + v)。
这里要注意我们在遍历每一行的时候必须逆向遍历，这样才能够调用 上一行物品 i-1 时 dp[j-w] 的值;
若按照从左往右的顺序进行正向遍历，则 dp[j-w] 的值在遍历到 j 之前就已经被更新成物品 i 的值了。
*/
int knapsack(vector<int> weights, vector<int> values, int N, int W){
    vector<int> dp(W + 1, 0);
    for(int i=1; j<=W; ++j){
        nt w = weights[i-1], v = values[i];
        for(int j>=W; j>=w; --j){
            dp[j] = max(dp[j],[j-w] + v);
        }
    }
    return dp[W]
}

/***    
    完全背包：
    不限定每种物品的数量

题解：
    假设我们遍历到物品 i = 2， 且其体积为 w = 2，价值为 v = 3;对于背包容量 j = 5，最多只能装下 2 个该物品。
    那么我们的状 态转移方程就变成了 dp[2][5] = max(dp[1][5], dp[1][3] + 3, dp[1][1] + 6)。如果采用这种方法，
    假设 背包容量无穷大而物体的体积无穷小，我们这里的比较次数也会趋近于无穷大，远超 O(NW) 的 时间复杂度。
    怎么解决这个问题呢?我们发现在 dp[2][3] 的时候我们其实已经考虑了 dp[1][3] 和 dp[2][1] 的情况，
    而在时 dp[2][1] 也已经考虑了 dp[1][1] 的情况。因此，如图下半部分所示，对于拿多个 物品的情况，我们只需考虑 dp[2][3] 即可，
    即 dp[2][5] = max(dp[1][5], dp[2][3] + 3)。这样，我们 就得到了完全背包问题的状态转移方程:dp[i][j] = max(dp[i-1][j], dp[i][j-w] + v)，
    其与 0-1 背包问 题的差别仅仅是把状态转移方程中的第二个 i-1 变成了 i。

    
***/
int knapsack(vector<int> weights, vector<int> values, int N, int W){
    vector<vector<int>> dp(N+1, vector<int>(W+1, 0));

    for(int i=1; i<=N; ++i){
        int w = weights[i-1], v = values[i];
        for(int j=1; j<=W; ++j){
            if(j >= w)
                dp[i][j] = max(dp[i-1][j],dp[i][j-w] + v);//可以理解为应该是和已经拿过第i个物品但是重量不超过j-w的比较
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[N][W]
}

//压缩， 正向遍历
int knapsack(vector<int> weights, vector<int> values, int N, int W){
    vector<int> dp(W + 1, 0);
    for(int i=1; j<=W; ++j){
        nt w = weights[i-1], v = values[i];
        for(int j=w; j>=W; --j){
            dp[j] = max(dp[j],[j-w] + v);
        }
    }
    return dp[W]
}
