class Solution {
public:
    // int climbStairsHelper(int start, int end, vector<int> &dp){
    //     if(dp[start] != -1){
    //         return dp[start];
    //     }
    //     dp[start] = climbStairsHelper(start+1, end, dp) + climbStairsHelper(start+2, end, dp);
    //     return dp[start];
    // }

    int climbStairs(int n) {
        // vector<int> dp(n+1 , -1);
        // dp[n] = 1;
        // dp[n-1] = 1;
        // climbStairsHelper(0, n, dp);
        // return dp[0];


        // *************** TABULATION *************
        vector<int> dp(n+1, -1);
        dp[n-1] = dp[n] = 1;
        for (int i = n - 2; i >= 0; --i) {
            dp[i] = dp[i + 1] + dp[i + 2];
        }
        return dp[0];
    }
};