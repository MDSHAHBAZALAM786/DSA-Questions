class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m == 0) return 0;

        // Build LPS (Longest Prefix Suffix) array
        vector<int> lps(m, 0);
        int j = 0;
        for (int i = 1; i < m; ) {
            if (needle[i] == needle[j]) {
                lps[i] = j + 1;
                i++, j++;
            } else {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // KMP Search
        j = 0;
        for (int i = 0; i < n; ) {
            if (haystack[i] == needle[j]) {
                i++, j++;
                if (j == m) return i - m;
            } else {
                if (j != 0) j = lps[j - 1];
                else i++;
            }
        }
        return -1;
    }
};
