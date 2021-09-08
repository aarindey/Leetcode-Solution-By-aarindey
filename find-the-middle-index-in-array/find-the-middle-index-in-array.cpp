class Solution {
public:
  int findMiddleIndex(vector<int>& nums) {
int suml,sumr,n=nums.size();
    for(int i=0;i<n;i++)
    {
        suml=sumr=0;
        if(i!=0)
        for(int j=0;j<i;j++)
        {
            suml+=nums[j];
        }
        if(i!=n-1)
        for(int j=i+1;j<n;j++)
        {
            sumr+=nums[j];
        }
        if(suml==sumr)
            return i;
    }
    return -1;
    }
};