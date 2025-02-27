#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        unordered_map<int, int> freq; // Store frequency of elements
        sort(nums.begin(), nums.end()); // Step 1: Sort the array

        long long left = 0, total = 0, maxFreq = 1;
        
        for (long long right = 0; right < nums.size(); right++) {
            total += nums[right]; // Maintain window sum
            
            // Condition: If making all elements in window equal to nums[right] exceeds k
            while ((right - left + 1) * nums[right] - total > k) {
                total -= nums[left]; // Remove leftmost element
                left++;
            }
            
            freq[nums[right]]++; // Store frequency in hashmap
            maxFreq = max(maxFreq, right - left + 1);
        }
        
        return maxFreq;
    }
};
