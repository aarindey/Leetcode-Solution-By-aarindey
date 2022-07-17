class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& d)
    {
        sort(nums.begin(),nums.end());
        int gcdd=d[0];
        for(int i=0;i<d.size();i++)
            gcdd=__gcd(d[i],gcdd);
        
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(gcdd%nums[i]==0)
            return i;
        }
        return -1;
    }
};