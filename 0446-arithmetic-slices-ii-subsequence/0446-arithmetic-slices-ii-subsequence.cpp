class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<unordered_map<long, long> > dp(nums.size());
        int ans = 0 ;
        for (int i = 0; i < nums.size() ; i++) 
        {
            for (int j = 0; j < i ; j++) 
            {
                long diff = (long)nums[i] - (long)nums[j] ; 
                dp[i][diff]++ ;
                if(dp[j].find(diff) != dp[j].end()) // Check for key 
                {
                    dp[i][diff] += dp[j][diff]; 
                    ans += dp[j][diff] ;
                }
            }
        }
        return ans ;
    }
};