// #include<bits/stdc++.h>
class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        // Brute Force
        // int n = nums.size();
        // k = k%n;
        // vector<int> temp(k);
        // for (int i = 0; i < k; i++) {
        //     temp[i] = nums[n - k + i];
        // }
        // for (int i = n - k - 1; i >= 0; i--) {
        //     nums[i + k] = nums[i];
        // }
        // for (int i = 0; i < k; i++) {
        //     nums[i] = temp[i];
        // }

        // Optimal Solution
        int n = nums.size();
        k = k%n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};