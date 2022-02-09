class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        int equal=0;
        vector<int> less,more;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==pivot)
            {
                equal++;
            }
            else if(nums[i]<pivot)
            {
                less.push_back(nums[i]);
            }
            else 
            {
                more.push_back(nums[i]);
            }
        }
        int i=0;
        for(;i<less.size();i++)
        {
            nums[i]=less[i];
        }
        while(equal--)
        {
            nums[i++]=pivot;
        }
        for(int j=0;j<more.size();j++)
        {
            nums[i++]=more[j];
        }
        return nums;
    }
};