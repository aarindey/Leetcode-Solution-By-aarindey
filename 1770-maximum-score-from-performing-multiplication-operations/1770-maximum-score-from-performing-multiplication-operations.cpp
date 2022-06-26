class Solution {
public:
    
 
    vector<vector<int>>dp;
    int recurs(vector<int>& n, vector<int>& m,int i,int k)
    {
        
        if(k>=m.size())
        {
            return 0;
        }
           
        if(dp[i][k]!=INT_MAX)
        {
            return  dp[i][k];
        }
        
        int j=n.size()-(k-i)-1;
        int a= max( recurs(n,m,i+1,k+1)+(n[i]*m[k]),recurs(n,m,i,k+1)+(n[j]*m[k]));
        return dp[i][k]=a;
        
    }
    
    int maximumScore(vector<int>& nums, vector<int>& m) {
        dp.resize(m.size()+1,vector<int>(m.size()+1,INT_MAX));
        return recurs(nums,m,0,0);
    }
};