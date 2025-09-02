class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // STL Approcah
        // next_permutation(nums.begin(),nums.end());

        // Optimal Solution
       int n = nums.size();
        if (n <= 1) return;  // ✅ safety for empty or single-element cases

        int index = -1;

        // Step 1: Find pivot
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index = i;
                break;
            }
        }

        // Step 2: If no pivot, reverse whole array
        if (index == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find element just greater than pivot
        for (int i = n - 1; i > index; i--) {
            if (nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }

        // Step 4: Reverse suffix
        reverse(nums.begin() + index + 1, nums.end());
    }
};