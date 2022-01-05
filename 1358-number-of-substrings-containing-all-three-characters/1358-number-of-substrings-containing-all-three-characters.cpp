class Solution {
public:
    int numberOfSubstrings(string s) {
       vector<int> count(3,0);
       int j=0,ans=0;
        int n=s.length();
       for(int i=0;i<n;i++)
       {
           count[s[i]-'a']++;
           while(count[0]&&count[1]&&count[2])
           {
               count[s[j]-'a']--;
               j++;
           }
           ans+=j;
       }
        return ans;
    }
};