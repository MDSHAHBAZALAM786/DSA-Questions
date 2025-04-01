class Solution {
public:
    long long mostPoints(vector<vector<int>>& A) {
        long long N = A.size();
        vector<long long> dp(N + 2);
        for (int i = 0; i < N; ++i) {
            int next = i + A[i][1] + 2;
            if (next > N) next = N + 1;
            dp[i + 1] = max(dp[i + 1], dp[i]);
            dp[next] = max(dp[next], dp[i + 1] + A[i][0]);
        }
        return *max_element(begin(dp), end(dp));
    }
};