class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int start = 0;
        int end = n-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid]>nums[end]){
                start = mid+1;
            }else{
                ans = min(ans,nums[mid]);
                end = mid - 1;
            }
        }
        return ans;
    }
};