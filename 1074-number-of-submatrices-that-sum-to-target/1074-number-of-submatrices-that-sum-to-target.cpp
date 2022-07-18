#define ll long long int
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        ll ans=0;
        for(int i=0;i<matrix.size();i++)
        {
            vector<ll> v(matrix[0].size(),0);
            for(int j=i;j<matrix.size();j++)
            {
                ll sum=0;
                unordered_map<ll,int> mp;
                for(int k=0;k<matrix[0].size();k++)
                {
                    
                    v[k]+=(ll)matrix[j][k]; 
                    sum+=v[k];
                    if(sum==target)
                    ans++;
                    if(mp.find(sum-target)!=mp.end())
                    ans+=mp[sum-target];
                    if(mp.find(sum)!=mp.end())
                    mp[sum]=mp[sum]+1;
                    else
                    mp[sum]=1;   
                }
            }
        }
        return ans;
        
    }
};