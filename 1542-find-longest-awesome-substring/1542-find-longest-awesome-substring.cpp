class Solution {
public:
    int longestAwesome(string s) {
        int n=s.size();
        map<int,int> mp;
        mp[0]=-1;
        int state=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int mask=(1<<(s[i]-'0'));
            state=(state^mask);
            if(mp.find(state)!=mp.end())
            {
                int j=mp[state];
                ans=max(ans,i-j);
            }
            for(int k=0;k<=9;k++)
            {
                int mask=(1<<k);
                int state2=state^mask;
                if(mp.find(state2)!=mp.end())
                {
                    int j=mp[state2];
                    ans=max(ans,i-j);
                }
            }
            if(mp.find(state)==mp.end())
            mp[state]=i;
        }
        return ans;
    }
};