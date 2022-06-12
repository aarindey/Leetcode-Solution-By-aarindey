class Solution {
public:
    int ans=INT_MAX;
    void solve(vector<int> &cookies,int k,vector<int> &sum,int i,int n)
    {
        if(i==n)
        {
            int sumMax=INT_MIN;
            for(int j=0;j<k;j++)
            {
                sumMax=max(sumMax,sum[j]);
            }
            ans=min(ans,sumMax);
            return;
        }
        
        for(int j=0;j<k;j++)
        {
            sum[j]+=cookies[i];
            solve(cookies,k,sum,i+1,n);
            sum[j]-=cookies[i];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> sum(k,0);
        int n=cookies.size();
        solve(cookies,k,sum,0,n);
        return ans;
    }
};