class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goodIndex=nums.size()-1;
        for(int i=nums.size()-2;i>=0;i--)
        {
            if((i+nums[i])>=goodIndex)
            goodIndex=i;    
        }
        return goodIndex==0;
    }
};