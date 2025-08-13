class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

                // Brute Force
        // set<int> st;
        // for(int i=0;i<nums.size();i++){
        //     st.insert(nums[i]);
        // }
        // int index = 0;
        // for(auto it:st){
        //     nums[index] = it;
        //     index++;
        // }
        // nums.resize(index);
        // return index;

        int n = nums.size();
        int i = 0;
        for(int j=1; j<n; j++){
            if(nums[i] != nums[j]){
                nums[i+1] = nums[j];
                i++;
            }
        }
        return i+1;
    }
};