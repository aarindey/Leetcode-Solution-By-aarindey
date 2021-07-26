class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int mini=INT_MAX;
        int prev=-1;
        for(int i=0;i<nums.size();i++)
        {
             if(prev==-1&&nums[i]==1)
            {
                prev=i; 
            }  
            else if(prev!=-1&&nums[i]==1)
             {
                 if((i-prev-1)<mini)
                 {
                  mini=i-prev-1; 
                 }   
                 prev=i;
             } 
        }
       if(mini>=k)
         return true;
        else
         return false;   
    }
};