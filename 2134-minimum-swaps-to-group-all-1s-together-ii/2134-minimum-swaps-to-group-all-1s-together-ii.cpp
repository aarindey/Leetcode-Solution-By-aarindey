class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int countOnes=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            countOnes++;
        }
        if(countOnes==0)
        return 0;
        int windowSize=countOnes;
        for(int i=0;i<n;i++)
        nums.push_back(nums[i]);
        n=nums.size();
        vector<int> prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+nums[i];
        }
        int ans=windowSize-prefix[windowSize-1];
        for(int i=0;i<n-windowSize;i++)
        {
            ans=min(ans,windowSize-(prefix[i+windowSize]-prefix[i]));
        }
        return ans;
    }
};