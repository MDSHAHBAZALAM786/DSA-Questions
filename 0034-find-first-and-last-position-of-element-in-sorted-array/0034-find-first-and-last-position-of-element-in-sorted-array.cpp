class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int left = -1;
        int right = -1;
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                left=i;
                break;
            }
        }
        for(int i=n-1;i>=0;--i){
            if(nums[i]==target){
                right=i;
                break;
            }
        }
        return{left,right};
    }
};