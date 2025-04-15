class Solution {
public:
    long long goodTriplets(vector<int>& A, vector<int>& B) {
        long N = A.size(), ans = 0;
        vector<int> m(N), lt(N), tmp(N), tmpLt(N), index(N);
        for (int i = 0; i < N; ++i) m[A[i]] = i;
        for (int i = 0; i < N; ++i) {
            B[i] = m[B[i]];
            index[B[i]] = i;
        }
        function<void(int, int)> merge = [&](int begin, int end) {
            if (begin + 1 >= end) return;
            int mid = (begin + end) / 2;
            merge(begin, mid);
            merge(mid, end);
            int i = begin, j = mid, k = begin;
            for (; k < end; ++k) {
                if (j >= end || (i < mid && B[i] < B[j])) {
                    tmp[k] = B[i];
                    tmpLt[k] = lt[i];
                    ++i;
                } else {
                    tmp[k] = B[j];
                    tmpLt[k] = lt[j] + i - begin;
                    ++j;
                }
            }
            for (int i = begin; i < end; ++i) {
                B[i] = tmp[i];
                lt[i] = tmpLt[i];
            }
        };
        merge(0, N);
        for (int i = 0; i < N; ++i) {
            ans += (long)lt[i] * (N - B[i] - 1 - index[B[i]] + lt[i]);
        }
        return ans;
    }
};