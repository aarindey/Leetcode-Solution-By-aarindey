class Solution {
public:
    int findDuplicate(vector<int>& nums) {
     int slow=nums[0],fast=nums[0];
     do
     {
         fast=nums[nums[fast]];
         slow=nums[slow];
     }while(slow!=fast);
     fast=nums[0];
        while(slow!=fast)
        {
            fast=nums[fast];
            slow=nums[slow];
        }
        return slow;
    }
};