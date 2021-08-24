class Solution {
public:
    int specialArray(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    for(int x=1;x<=nums.size();x++)
    {
        int c=0;
        for(int j=nums.size()-1;j>=0;j--)
        {
            if(nums[j]>=x)
            c++;
        }
        if(c==x)
        return x;    
    }
    return -1;
    }
};