class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n=nums.size();
        int total_ones=accumulate(nums.begin(),nums.end(),0);
        int c=total_ones;
        int num;
        vector<int> ans;
        int curr_ones=0;
        ans={0};
        for(int i=1;i<=n;i++)
        {
        curr_ones+=nums[i-1];
        num=i-curr_ones+total_ones-curr_ones;
        if(num>c)
        {
            ans={i};
            c=num;
        }
        else if(num==c)
        {
            ans.push_back(i);
        }
        }
        return ans;
    }
};