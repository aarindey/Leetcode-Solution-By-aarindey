class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int cand=nums[0],count=1;
        for(int i=1;i<nums.size();i++)
          {
              if(cand==nums[i])
                  count++;
            else 
            {
                count--;
            if(count==0)
            {
                cand=nums[i];
                count=1; 
            }
            }
        }
        return cand;
    }
};