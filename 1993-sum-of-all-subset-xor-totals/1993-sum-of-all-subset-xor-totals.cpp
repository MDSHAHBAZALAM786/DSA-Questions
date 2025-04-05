class Solution {
    int ans = 0;
    void dfs(vector<int> &A, int start, int val) {
        if (start == A.size()) {
            ans += val;
            return;
        }
        dfs(A, start + 1, val ^ A[start]);
        dfs(A, start + 1, val);
    }
public:
    int subsetXORSum(vector<int>& A) {
        dfs(A, 0, 0);
        return ans;
    }
};