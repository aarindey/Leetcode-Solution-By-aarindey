class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int currSum=0,count=0;
        for(int i=0;i<nums.size();i++)
        {
            currSum+=nums[i];
            if(currSum-k==0)
            count++; 
            if(mp.find(currSum-k)!=mp.end())
             count+=mp[currSum-k];
            mp[currSum]++;
        }
        return count;
    }
};