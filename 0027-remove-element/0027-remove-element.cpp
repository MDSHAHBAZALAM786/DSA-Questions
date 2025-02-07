class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; // Pointer to store the position of non-val elements
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i]; // Move valid element to the front
                k++;
            }
        }
        return k;
    }
};