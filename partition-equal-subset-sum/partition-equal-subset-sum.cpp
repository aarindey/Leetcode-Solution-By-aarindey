class Solution {
public:
bool canPartition(vector<int> &nums) {

    int n=nums.size();
    
    int sum=accumulate(nums.begin(),nums.end(),0);
    
    // We have to divide the whole array into two non-empty subsets .
    
    // Again sum of subset1 == sum of subset2
    
    // That means sum of subset1 + sum of subset2 == sum of array
    
    // 2 * sum of subset1 == sum of array
    
    // Sum of subset1 == Sum of subset2 == ( sum of array / 2 )
    
    // Which clearly shows that the sum of array elements should be even.
    
    // Edge Case Handling.
    
    if(sum%2!=0){
        return false;
    }
    
    int target=sum/2;
    
    
    // Now we have to figure out whether we can form (target) by using one or more than one elements , as If we able to form target then it is already proved that (sum of array - target) automatically goes to another subset.
    
    
    vector<bool>dp(target+1);
    
    // Base Condition , as we can get 0 without disturbing any of the array element.
    
    dp[0]=true;
    
    // Most Popular Way to solve these type of problem is using DP.
    
    for(int i=0;i<n;i++){
        
        
        // Now for the first time it arises doubt that why the inner loop runs in backward direction.
        
        // Just do a dry run first running the loop in backward direction and then in forward direction. Then it is crystal clear to you.
        
        for(int j=target;j>=nums[i];j--){
            
            dp[j]=dp[j] || dp[j-nums[i]];
            
        }
        
    }
    
    return dp[target];
    
}
};