class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n=nums.size();
        int total_ones=accumulate(nums.begin(),nums.end(),0);
        int c=total_ones;
        int num;
        unordered_map<int,vector<int>> mp;
        mp[c].push_back(0);
        int curr_ones=0;
        for(int i=1;i<=n;i++)
        {
        curr_ones+=nums[i-1];
        num=i-curr_ones+total_ones-curr_ones;
        c=max(c,num);
        mp[num].push_back(i);
        }
        return mp[c];
    }
};