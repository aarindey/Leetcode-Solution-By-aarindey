class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        vector<int> pre(n+1,0);
        for(int i=1;i<=n;i++)
        {
            pre[i]=arr[i-1]^pre[i-1];
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int k=j;k<=n;k++)
                {
                    if(pre[j-1]^pre[i-1]==pre[k]^pre[j-1])
                    ans++;
                }
            }
        }
        return ans;
    }
};