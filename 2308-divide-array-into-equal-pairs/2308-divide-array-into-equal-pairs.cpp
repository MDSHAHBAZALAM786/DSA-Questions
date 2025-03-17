class Solution {
public:
    bool divideArray(vector<int>& A) {
        unordered_map<int, int> m;
        for (int n : A) m[n]++;
        for (auto &[n, cnt] : m) {
            if (cnt % 2) return false;
        }
        return true;
    }
};