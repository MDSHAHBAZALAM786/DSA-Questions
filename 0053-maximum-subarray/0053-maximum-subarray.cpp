class Solution {
public:
    int maxSubArray(vector<int>& nums) {
            // Not Working O(N^3)
        // int maxSubArrSum = INT_MIN;
        // int n = nums.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         int currSubArrSum = 0;
        //         for(int k=i;k<=j;k++){
        //             currSubArrSum += nums[k]; 
        //         }
        //         maxSubArrSum = max(maxSubArrSum, currSubArrSum);
        //     }
        // }
        // return maxSubArrSum;


            // Not Working O(N^2)
        // int n = nums.size();
        // int maxSubArrSum = INT_MIN;
        // for(int i=0;i<n;i++){
        //     int currSubArrSum = 0;
        //     for(int j=i;j<n;j++){
        //         currSubArrSum += nums[j];
        //         maxSubArrSum = max(maxSubArrSum, currSubArrSum);
        //     }
        // }
        // return maxSubArrSum;


        // Working O(N)
        int n = nums.size();
        int maxSubArrSum = INT_MIN;
        int currSubArrSum = 0;
        for(int i=0;i<n;i++){
            currSubArrSum += nums[i];
            maxSubArrSum = max(maxSubArrSum, currSubArrSum);
            if(currSubArrSum < 0){
                currSubArrSum = 0;
            }
        }
        return maxSubArrSum;
    }
};