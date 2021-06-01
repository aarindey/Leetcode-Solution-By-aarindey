class Solution {
public:
 int maxAscendingSum(vector<int> nums) {
int result=0;
int anchor=0;
int curr_sum=0;

    for(int i=0;i<nums.size();i++){
        if(i>0 && nums[i-1]>=nums[i]) 
        {
            anchor=i;
            curr_sum=0;
        }
        curr_sum=curr_sum+nums[i];
        result=max(result,curr_sum);
    }
    return result;
}
};