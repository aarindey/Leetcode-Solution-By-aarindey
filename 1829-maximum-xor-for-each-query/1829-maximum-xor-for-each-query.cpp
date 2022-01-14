class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size();
        vector<int> prefixXor(n);
        prefixXor[0]=nums[0];
        vector<int> ans;
        for(int i=1;i<n;i++)
        {
            prefixXor[i]=prefixXor[i-1]^nums[i];
        }
        for(int i=n-1;i>=0;i--)
        {
            int k=0;
            for(int j=0;j<maximumBit;j++)
            {
                if(!(prefixXor[i]&(1<<j)))
                {
                    k+=(1<<j);
                }
            }
            ans.push_back(k);
        }
        return ans;
    }
};