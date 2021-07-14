class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0)
         return 0;
        if(haystack.size()<needle.size())
          return -1;  
        int n=needle.size();
        string str;
        for(int i=0;i<=haystack.size()-n;i++)
        {
            str=haystack.substr(i,n);
            if(str==needle)
             return i;   
        }
        return -1;
    }
};