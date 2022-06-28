class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> mp1;
        unordered_map<int,int> mp2;
        for(char &ch:s)
        {
            mp1[ch]++;
        }
        bool ok=true;
        for(auto &pr:mp1)
        {
            mp2[pr.second]++;
            if(mp2[pr.second]==2)
            {
                ok=false;
            }
        }
        if(ok)
        {
            return 0;
        }
        int ans=0;
        for(auto &pr:mp2)
        {
            int x;
            int y=pr.second;
            while(mp2[pr.first]>1)
            {
                x=pr.first;
                mp2[pr.first]--;
                x--;
                ans++;
                while(mp2.find(x)!=mp2.end())
                {
                    ans++;
                    x--;
                }
                if(x!=0)
                {
                    mp2[x]++;
                }
            }
        }
        return ans;
    }
};