class Solution {
public:
    int minSwaps(string s) {
        int n=s.size(),ans=0;;
        int opening=0,closing=0;
          int j=n-1;
       for(int i=0;i<n;i++)
       {
           if(s[i]=='[')
           {
               opening++;
           }
           else
           {
               closing++;
           }
           if(closing>opening)
           {
               while(j>=0&&s[j]!='[')
               {
                   j--;
               }
               swap(s[i],s[j]);
               closing--;
               opening++;
               ans++;
           }
       }
        return ans;
    }
};