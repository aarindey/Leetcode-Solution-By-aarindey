class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
     int n=nums.size();
        int c1=0,c2=0;
        vector<int> nums2=nums;
        if(n==1)
        {
            return 0;
        }
        else if(n==2)
        {
            return nums[0]==nums[1];
        }
        for(int i=0;i<n;i+=2)
        {
            if(i==0)
            {
                if(nums[i]>nums[i+1])
                {
                    continue;
                }
                c1+=(nums[i+1]-nums[i])+1;
                nums[i+1]=nums[i]-1;
            }
            else if(i==n-1&&i%2==0)
            {
                if(nums[i]>nums[i-1])
                {
                    continue;
                }
                c1+=(nums[i-1]-nums[i])+1;
                nums[i-1]=nums[i]-1;
            }
            else
            {
                if(nums[i]>nums[i-1]&&nums[i]>nums[i+1])
                {
                    continue;
                }
                if(nums[i-1]>=nums[i])
                {
                    c1+=(nums[i-1]-nums[i])+1;
                    nums[i-1]=nums[i]-1;
                }
                if(nums[i+1]>=nums[i])
                {
                    c1+=(nums[i+1]-nums[i])+1;
                    nums[i+1]=nums[i]-1;
                }
            }
        }
        nums=nums2;
        c2=0;
        for(int i=1;i<n;i+=2)
        {
            if(i==n-1)
            {
                if(nums[i]>nums[i-1])
                {
                    continue;
                }
                c2+=(nums[i-1]-nums[i])+1;
                nums[i-1]=nums[i]-1;
            }
            else 
            {
                if(nums[i]>nums[i-1]&&nums[i]>nums[i+1])
                {
                    continue;
                }
                if(nums[i-1]>=nums[i])
                {
                    c2+=(nums[i-1]-nums[i])+1;
                    nums[i-1]=nums[i]-1;
                }
                if(nums[i+1]>=nums[i])
                {
                    c2+=(nums[i+1]-nums[i])+1;
                    nums[i+1]=nums[i]-1;
                }
            }
        }
        
        return min(c1,c2);
    }
};