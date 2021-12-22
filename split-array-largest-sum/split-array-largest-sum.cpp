class Solution {
public:
    #define ll long long int
    bool possible(vector<int> &nums,int value,int m)
    {
        int curr=0;
        for(auto num:nums)
        {
            if(num>value)
            return false;
            else if(curr+num<=value)
            curr+=num;
            else
            {
                --m;
                curr=num;
                if(m<0)
                return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        ll low=INT_MIN,high=0;
        for(auto &num:nums)
        {
            low=max(low,(long long)num);
            high+=num;
        }
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(possible(nums,mid,m-1))
            high=mid-1;
            else
            low=mid+1;
        }
        return low;
    }
};