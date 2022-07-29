class Solution {
public:
    int solve(string &s,int start,int end,int k)
    {
        if(end-start+1<k)
        return 0;
        if(end<start)
        return 0;
        vector<int> count(26,0);
        
        for(int i=start;i<=end;i++)
        {
            count[s[i]-'a']++;
        }
        int ans=INT_MIN;
        int low=start;
        bool ok=true;
        char ch;
        for(int i=start;i<=end;i++)
        {
            if(count[s[i]-'a']<k)
            {
                ans=max(ans,solve(s,low,i-1,k));
                low=i+1;
                ch=s[i];
                ok=false;
            }
        }
        
        if(ok)
        {
            ans=end-start+1;
            return ans;
        }
        if(s[end]!=ch)
        ans=max(ans,solve(s,low,end,k));
        return ans;
    }
    int longestSubstring(string s, int k) {
        int n=s.length();
        return solve(s,0,n-1,k);
    }
};