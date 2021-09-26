class Solution {
public:
    string makeFancyString(string s) {
     int count=0;
     char prev=s[0];
     int k=0;
     for(int i=0;i<s.length();i++)
     {
         if(s[i]==prev)
         {
             count++;
         }
         else
         {
             count=1;
             prev=s[i];
         }
         if(count<3)
         s[k++]=s[i];    
     }
        s.erase(k);
    return s;
    }
};