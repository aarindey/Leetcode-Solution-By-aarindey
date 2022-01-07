class Solution {
public:
    int helper(vector<int> &nums,int k)
    {
     if(k==0)
     return 0;
     
     int j=0;
     int n=nums.size();
     unordered_map<int,int> freq;
     int total=0;
     int diff=0;
     for(int i=0;i<n;i++)
     {
        if(freq[nums[i]]==0)
        diff++;
        freq[nums[i]]++;
        if(diff<=k)
        {
           total+=(i-j+1);
        }
        else
        {
            while(j<n&&j<=i&&diff>k)
            {
                freq[nums[j]]--;
                if(freq[nums[j]]==0)
                diff--;
                j++;
            }
            total+=(i-j+1);
        }
     }
     return total;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
    }
};