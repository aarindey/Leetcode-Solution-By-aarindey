class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n=accounts.size();
        int s=INT_MIN;
        for(int i=0;i<n;i++)
        {
         int sum=0;
         vector<int> v;
            for(int j=0;j<accounts[i].size();j++)
            {
                v=accounts[i];
                sum+=v[j];
            }
         if(sum>s)
         {
             s=sum;
         }
        }
        return s;
        
    }
};