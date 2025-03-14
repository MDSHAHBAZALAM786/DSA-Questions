class Solution {
public:
    int maximumCandies(vector<int>& A, long long k) {
        long L = 1, R = *max_element(begin(A), end(A)), N = A.size();
        auto valid = [&](long m) {
            long cnt = 0;
            for (int n : A) {
                cnt += n / m;
                if (cnt >= k) return true;
            }
            return false;
        };
        while (L <= R) {
            long M = L + (R - L) / 2;
            if (valid(M)) L = M + 1;
            else R = M - 1;
        }
        return R;
    }
};