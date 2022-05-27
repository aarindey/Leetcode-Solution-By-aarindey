class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
     string ans="";
        for(auto it=s.rbegin();it!=s.rend();it++)
        {
         if(*it=='-')
         {
             continue;
         }
         else
         {
             if(ans.size()%(k+1)==k)
                ans+='-';
             ans+=toupper(*it);
         }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};