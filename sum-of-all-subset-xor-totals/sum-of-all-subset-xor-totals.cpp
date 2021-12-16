class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        int collect_bits=0;
        for(int &num:nums)
        collect_bits|=num;
        int ans=pow(2,n-1)*collect_bits;
        return ans;
    }
};