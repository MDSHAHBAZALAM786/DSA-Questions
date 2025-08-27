class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // Brute force
        // for(int i=0;i<nums.size();i++){
        //     nums[i] = nums[i]*nums[i];
        // }
        // sort(nums.begin(),nums.end());
        // return nums;

        // Optimal Solution
        vector<int> temp;
        temp.reserve(nums.size());
        for(int i:nums){
            temp.push_back(i*i);
        }
        sort(temp.begin(),temp.end());
        return temp;
    }
};