class Solution {
public:
    unordered_map<string,bool> mp;
    bool solve(string s1,string s2)
    {
     
        if(s1==s2)
        {
            return true;
        }
        if(s1.size()!=s2.size())
        {
            return false;
        }
        if(s1.size()<1)
        {
            return false;
        }
        string key=s1+" "+s2;
        if(mp.find(key)!=mp.end())
        {
            return mp[key];
        }
        
        bool flag=false;
        int n=s1.size();
        for(int k=1;k<=n-1;k++)
        {
            bool cond1,cond2;
            cond1=solve(s1.substr(0,k),s2.substr(0,k))&&solve(s1.substr(k,n-k),s2.substr(k,n-k));
            cond2=solve(s1.substr(0,k),s2.substr(n-k,k))&&solve(s1.substr(k,n-k),s2.substr(0,n-k));
            if(cond1||cond2)
            {
                flag=true;
                break;
            }
        }
        return mp[key]=flag;
    }
    bool isScramble(string s1, string s2) {
        return solve(s1,s2);
    }
};