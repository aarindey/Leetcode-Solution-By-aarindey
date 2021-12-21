class Solution {
public:
    long long int mod=1e9+7;
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int,long> mp;
        for(int &x:arr)
        {
            mp[x]++;
        }
        long long int ans=0;
        for(auto &pr:mp)
        {
            int i=pr.first;
            for(auto &pr2:mp)
            {
                int j=pr2.first;
                int k=target-i-j;
                if(k<0||k>100||mp.find(k)==mp.end())
                continue;
                if(i==j&&j==k)
                {
                    ans+=mp[i]*(mp[i]-1)*(mp[i]-2)/6;
                }
                else if(i==j&&j!=k)
                {
                    ans+=mp[k]*mp[i]*(mp[i]-1)/2;
                }
                else if(i<j&&j<k)
                {
                    ans+=mp[i]*mp[j]*mp[k];
                }
            }
        }
        return (int)(ans%mod);
    }
};