class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

            // Linear Search
        // int n=nums.size();
        // int left = -1;
        // int right = -1;
        // for(int i=0;i<n;i++){
        //     if(nums[i]==target){
        //         left=i;
        //         break;
        //     }
        // }
        // for(int i=n-1;i>=0;--i){
        //     if(nums[i]==target){
        //         right=i;
        //         break;
        //     }
        // }
        // return{left,right};


            // Binary Search
        int n=nums.size();
        int start=0;
        int end=n-1;
        int left= -1;
        int right= -1;
        // For right occurrence
        while(start<= end){
            int mid=(start+end)/2;
            if(nums[mid]>target){
                end=mid-1;
            }else if(nums[mid]<target){
                start=mid+1;
            }else{
                right=mid;
                start=mid+1;
            }
        }
        // For left occurrence
        start=0;
        end=n-1;
        while(start<= end){
            int mid=(start+end)/2;
            if(nums[mid]>target){
                end=mid-1;
            }else if(nums[mid]<target){
                start=mid+1;
            }else{
                left=mid;
                end=mid-1;
            }
        }
        return {left,right};
    }
};