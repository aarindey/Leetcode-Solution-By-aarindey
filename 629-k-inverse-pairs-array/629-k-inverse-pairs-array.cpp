class Solution {
public:
    #define mod 1000000007
    int kInversePairs(int n, int k) {
        memset(dp, -1, sizeof dp);
        
        int ans = recur(n - 1, k);
        return ans < 0 ? ans + mod : ans;
    }
    
    int recur(int curr_index, int curr_pairs){
        if(curr_index == 0 && curr_pairs > 0) return 0;
        if(curr_pairs == 0) return 1;
        
        if(dp[curr_index][curr_pairs] == -1){
            dp[curr_index][curr_pairs] = (recur(curr_index - 1, curr_pairs) + recur(curr_index, curr_pairs - 1)) % mod;
            
            if(curr_index < curr_pairs){
                dp[curr_index][curr_pairs] -= (recur(curr_index - 1, curr_pairs - curr_index - 1)) % mod;
            }
        }
    
        return dp[curr_index][curr_pairs] % mod;
    }
    
    int dp[1002][1002] = {};
};