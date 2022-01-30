class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp;
        map<int,int> mp;
        int k=0;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]<3)
            {
                temp.push_back(nums[i]);
                k++;
            }
        }
        for(int i=0;i<temp.size();i++)
        {
            nums[i]=temp[i];
        }
        return k;
    }
};