class Solution {
public:
    bool checkRecord(string s) {
        int c=0;
        int l=0;
        for(int i=0;i<s.length();i++)
        {
           if(s[i]=='A')
           {
            c++;
            l=0;   
           }   
           else if(s[i]=='L')
           {
              l++; 
           }
           else
           l=0;    
            if(c>=2||l>=3)
              return false;
        }
        return true;
    }
};