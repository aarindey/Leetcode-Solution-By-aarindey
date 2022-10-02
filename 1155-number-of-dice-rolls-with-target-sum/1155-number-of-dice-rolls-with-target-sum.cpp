class Solution {
public:
long long MOD=1000000007;
int solve(int d,int f,int t) {
	vector<vector<int>> dp(d+1,vector<int>(t+1,0));
	dp[0][0] = 1;
	for(int dice=1;dice<=d;dice++) {
		for(int tar=1;tar<=t;tar++) {
			int ways=0;
			for(int i=1;i<=f;i++) {
				if(tar-i >= 0) {
					ways += dp[dice-1][tar-i];
					ways %= MOD;
				}
			}
			dp[dice][tar] = ways;
		}
	}
	return dp[d][t];
}
int numRollsToTarget(int d, int f, int target) {
	return solve(d, f, target);
}
};