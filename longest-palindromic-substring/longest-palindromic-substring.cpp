class Solution {
public:
    string longestPalindrome(string s) {
        string str;
        int len;
        int end=0,start=0;
   for(int i=0;i<s.length();i++)
   {
       int len1=expandFromCenter(s,i,i);
       int len2=expandFromCenter(s,i,i+1);
       len=max(len1,len2);
       if(len>end-start)
       {
           start=i-(len-1)/2;
           end=i+len/2;
       }  
   }
     return s.substr(start,end-start+1);   
   }
    int expandFromCenter(string s,int left,int right)
    {
        if(s.length()<1||left>right)
         return 0;
        while(left>=0&&right<s.length()&&s[left]==s[right])
        {
            left--;
            right++;
        } 
        return right-left-1;
    }
};