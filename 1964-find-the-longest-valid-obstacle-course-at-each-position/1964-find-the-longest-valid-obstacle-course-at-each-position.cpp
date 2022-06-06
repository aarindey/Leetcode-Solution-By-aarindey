class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums) {
        vector<int> temp;
        int n=nums.size();
        int length=1;
        temp.push_back(nums[0]);
        vector<int> ans(n);
        ans[0]=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>=temp.back())
            {
                temp.push_back(nums[i]);
                length++;
                ans[i]=length;
            }
            else
            {
                int idx=upper_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[idx]=nums[i];
                ans[i]=idx+1;
            }
        }
        return ans;
    }
};