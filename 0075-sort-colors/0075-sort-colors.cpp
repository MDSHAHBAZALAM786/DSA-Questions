class Solution {
public:
    void sortColors(vector<int>& nums) {
       int red=0,white=0,black=0;
       for(int x: nums){
        if(x==0) red++;
        else if(x==1) white++;
        else black++;
       }
        int index=0;
        while(red>0){
            nums[index]=0;
            index++;
            --red;
        }
        while(white>0){
            nums[index++]=1;
            white--;
        }
        while(black>0){
            nums[index++]=2;
            black--;
        }
    }
};