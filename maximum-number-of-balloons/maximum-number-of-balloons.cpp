class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp; 
        for(char c:text)
        {
            mp[c]++;
        }
        int ans=0;
      string b="balloon";
        while(true)
       {
           for(int i=0;i<b.length();i++)
           {
               if(mp[b[i]]==0)
               return ans;
               mp[b[i]]--;
           } 
            ans++;
       }
        return ans;
    }
};