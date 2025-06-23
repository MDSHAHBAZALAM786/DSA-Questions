class Solution {
public:
    bool isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
            return true;
        }else{
            return false;
        }
    }
    int maxVowels(string s, int k) {
        int start=0;
        int end=k-1;
        int count = 0;
        for(int i=0;i<k;i++){
            if(isVowel(s[i])){
                count++;
            }
        }
        int ans=count;
        while(end<s.size()){
            end++;
            // if(end==s.size()){
            //     break;
            // }
            if(isVowel(s[end])){
                count++;
            }
            if(isVowel(s[start])){
                count--;
            }
            start++;
            ans=max(ans,count);
        }
        return ans;
    }
};