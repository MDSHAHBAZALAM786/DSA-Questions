#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, int> index; // Hashmap to store element indices
    unordered_map<int, int> dp;    // Memoization table
    int n;  // Array size
    
    // Recursive function to compute longest Fibonacci sequence
    int findLongest(vector<int>& arr, int i, int j) {
        int key = i * n + j;
        if (dp.count(key)) return dp[key];  // Return memoized result
        
        int nextVal = arr[i] + arr[j];
        if (index.count(nextVal)) {
            int k = index[nextVal];
            dp[key] = 1 + findLongest(arr, j, k);
            return dp[key];
        }
        
        return dp[key] = 2;  // Default length is 2 if no Fibonacci sequence extends
    }
    
    int lenLongestFibSubseq(vector<int>& arr) {
        n = arr.size();
        int maxLen = 0;
        
        // Store index of each number in hashmap
        for (int i = 0; i < n; i++) {
            index[arr[i]] = i;
        }
        
        // Try all pairs as starting points
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                maxLen = max(maxLen, findLongest(arr, i, j));
            }
        }
        
        return maxLen >= 3 ? maxLen : 0;
    }
};
