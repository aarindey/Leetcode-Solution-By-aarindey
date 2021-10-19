class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());
    int maxi,mini;
    maxi=nums[nums.size()-1];
    mini=nums[0];
    if(k==0)
    return maxi-mini;
    else if(k>0)
    {
        maxi=maxi-k;
        mini=mini+k;
    }
    else if(k<0)
    {
        maxi=maxi+k;
        mini=mini-k;
    }
    if(maxi<=mini)
    return 0;
    return maxi-mini;
    }
};