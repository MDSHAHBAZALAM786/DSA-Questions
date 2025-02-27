class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); // Step 1: Sort array
        long long left = 0, total = 0, maxFreq = 1;
        
        for (long long right = 0; right < nums.size(); right++) {
            total += nums[right]; // Keep track of sum in the window
            
            // Check if the window is valid
            while ((right - left + 1) * nums[right] - total > k) {
                total -= nums[left]; // Shrink window from the left
                left++;
            }
            
            maxFreq = max(maxFreq, right - left + 1);
        }
        
        return maxFreq;
    }
};
