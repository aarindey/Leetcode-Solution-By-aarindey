class Solution {
public:
    int removePalindromeSub(string s) 
    {
      int n=s.length();
if(n==0)
    return 0;
        string k=s;
        reverse(k.begin(),k.end());
        if(k==s)
            return 1;
        else
            return 2;
    }
};