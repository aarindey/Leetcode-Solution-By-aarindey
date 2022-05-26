class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        int n=nums.size();
        int length=1;
        temp.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            if(nums[i]>temp.back())
            {
                temp.push_back(nums[i]);
                length++;
            }
            else
            {
                int idx=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[idx]=nums[i];
            }
        }
        return length;
    }
};