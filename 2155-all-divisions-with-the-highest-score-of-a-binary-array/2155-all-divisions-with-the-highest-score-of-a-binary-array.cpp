class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n=nums.size();
        int ones=accumulate(nums.begin(),nums.end(),0),zeroes=0,score=0;
        vector<int> ans;
        for(int i=0;i<=n;i++)
        {
         if(zeroes+ones>score)
         {
             score=zeroes+ones;
             ans.clear();
         }
         if(score==zeroes+ones)
         {
             ans.push_back(i);
         }
         if(i<n&&nums[i]==0)
         {
             zeroes++;
         }
         else
         {
             ones--;
         }
        }
        return ans;
    }
};