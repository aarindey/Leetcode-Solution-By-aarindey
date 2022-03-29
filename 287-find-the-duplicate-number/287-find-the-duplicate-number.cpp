class Solution {
public:
    int findDuplicate(vector<int>& nums){
       int n=nums.size();
        if(n<=1)
        return -1;
        else
        {
            int slow,fast;
            slow=nums[0];
            fast=nums[nums[0]];
            while(slow!=fast)
            {
                slow=nums[slow];
                fast=nums[nums[fast]];
                if(slow==fast)
                break;
            }
            fast=0;
            while(slow!=fast)
            {
                slow=nums[slow];
                fast=nums[fast];
            }
            return slow;
        }
        return -1;
    }
};