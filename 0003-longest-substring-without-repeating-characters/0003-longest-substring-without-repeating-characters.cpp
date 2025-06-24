class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start=0;
        int end=0;
        int maxLen=0;
        unordered_set<char> set;
        while(end<s.size()){
            char ch=s[end];
            while(set.find(ch) != set.end()){
                set.erase(s[start]);
                start++;
            }
            set.insert(ch);
            maxLen = max(maxLen, end-start+1);
            end++;
        }
        return maxLen;
    }
};