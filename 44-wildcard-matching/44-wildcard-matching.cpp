class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<bool> prev(m+1,false),curr(m+1,false);
        prev[0]=curr[0]=true;
        bool flag=true;
        for(int i=0;i<=m;i++)
        {
            if(i>=1&&p[i-1]!='*')
            {
                flag=false;
            }
            prev[i]=flag;
        }
        for(int i=1;i<=n;i++)
        {
            curr[0]=false;
            for(int j=1;j<=m;j++)
            {

                    if(s[i-1]==p[j-1]||p[j-1]=='?')
                    {
                        curr[j]=prev[j-1];
                    }
                    else if(p[j-1]=='*')
                    {
                        curr[j]=curr[j-1]||prev[j];
                    }
                    else
                    curr[j]=false;
            }
            prev=curr;
        }
        return prev[m];
    }
};