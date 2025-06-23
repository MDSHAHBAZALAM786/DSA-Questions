class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum=0;
        int maxSum = INT_MIN;
        int start=0;
        int end=k-1;
        for(int i=0;i<k;i++){
            sum += nums[i];
        }
        maxSum=sum;
        while(end<nums.size()){
            end++;
            if(end==nums.size()){
                break;
            }
            sum += nums[end];
            sum -= nums[start];
            start++;
            maxSum = max(maxSum, sum);
        }
        return (double)maxSum/k;
    }
};