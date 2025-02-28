class Solution {
public:
    string sortSentence(string s) {
        string Result = "";
        string True_result = "" ;
        vector <string> Words (10 , "") ;
      for (int st = 0 ; st <= s.length() - 1  ; st += 1)
      {
        if (isalpha(s[st]))
        {
            Result += s[st] ;
        }
        else if (s[st] - '0' <= 9 && s[st] != ' ')
        {
            Words[s[st] - '0'] = Result ;
            Result = "" ;
        }
      }
      for (int st = 1  ; st <= Words.size() - 1 ; st += 1)
      {
       True_result += Words[st] ;
       if (st != Words.size() - 1) True_result += ' ' ;
      }
      int end = True_result.length() - 1 ;
      while (True_result[end] == ' ') 
      {
        True_result.pop_back() ;
        end -= 1 ;
      }
      return True_result ; ;  
    }
};