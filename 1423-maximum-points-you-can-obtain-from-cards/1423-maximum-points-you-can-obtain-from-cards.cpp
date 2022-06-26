class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int n=v.size();
        vector<int> pre(n),suf(n);
        pre[0]=v[0];
        suf[n-1]=v[n-1];
        for(int i=1;i<n;i++)
        {
            pre[i]=pre[i-1]+v[i];
        }
        for(int i=n-2;i>=0;i--)
        {
            suf[i]=suf[i+1]+v[i];
        }
        int ans=INT_MIN;
        reverse(suf.begin(),suf.end());
        for(int i=0;i<k-1;i++)
        {
            ans=max(ans,pre[i]+suf[k-i-2]);
        }
        ans=max(ans,max(pre[k-1],suf[k-1]));
        return ans;
    }
};