class Solution {
public:
    int n;
    int merge(int start,int mid,int end,vector<int> &nums)
    {
        int i,j;
        i=start;
        j=mid+1;
        int pairs=0;
        for(int i=start;i<=mid;i++)
        {
            while(j<=end&&(2*1ll*nums[j]<nums[i]))
            {
                j++;
            }
            pairs+=j-(mid+1);
        }
        i=start;
        j=mid+1;
        vector<int> temp;
        while(i<=mid&&j<=end)
        {
            if(nums[i]<=nums[j])
            {
                temp.push_back(nums[i]);
                i++;
            }
            else
            {
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid)
        {
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=end)
        {
            temp.push_back(nums[j]);
            j++;
        }
        for(int i=0;i<temp.size();i++)
        {
            nums[i+start]=temp[i];
        }
        return pairs;
    }
    int mergeSort(int start,int end,vector<int> &nums)
    {
        if(start>=end)
        return 0;
        
        int pairs=0;
        int mid=start+(end-start)/2;
        pairs+=mergeSort(start,mid,nums);
        pairs+=mergeSort(mid+1,end,nums);
        pairs+=merge(start,mid,end,nums);
        return pairs;
    }
    int reversePairs(vector<int>& nums) {
        n=nums.size();
        return mergeSort(0,n-1,nums);
    }
};