class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0,count=0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
           sum+=nums[i];
            int remain = ((sum%k)+k)%k;
           if(mp.find(remain)!=mp.end())
           count+=mp[remain];
           mp[remain]++;
        }
        return count;
    }
};