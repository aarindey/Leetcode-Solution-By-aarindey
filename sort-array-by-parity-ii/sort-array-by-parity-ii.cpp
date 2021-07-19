class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        queue<int> q0;
        queue<int> q1;
        for(int i=0;i<n;i++)
        {
          if(nums[i]%2==0)
            q0.push(nums[i]);
           else 
            q1.push(nums[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                ans[i]=q0.front();
                q0.pop();
            }
            
            else if(i%2!=0)
            {
                ans[i]=q1.front();
                q1.pop();
            }
        }  
        return ans;
    }
};