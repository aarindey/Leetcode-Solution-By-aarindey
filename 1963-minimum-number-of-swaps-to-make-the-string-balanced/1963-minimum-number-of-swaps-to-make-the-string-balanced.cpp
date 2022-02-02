class Solution {
public:
    int minSwaps(string s) {
        int n=s.size(),ans=0;;
        int diff=0;
          int j=n-1;
       for(int i=0;i<n;i++)
       {
           if(s[i]=='[')
           {
               diff++;
           }
           else
           {
               diff--;
           }
           if(diff<0)
           {
               while(j>=0&&s[j]!='[')
               {
                   j--;
               }
               swap(s[i],s[j]);
               diff=1;
               ans++;
           }
       }
        return ans;
    }
};