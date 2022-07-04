class Solution {
public:
    int n;
    int total;
    bool check(int i,int j,vector<int> &nums,bool flag,int sum)
    {
        if(sum>=total-sum)
        return true;
        if(i==j)
        {
            if(2*(sum+nums[i])>=total)
            return true;
            else
            return false;
        }
        if(i>j)
        return false;
        bool ans=false;
        if(!flag)
        {
            if(check(i+1,j,nums,1,sum+nums[i])||check(i,j-1,nums,1,sum+nums[j]))
            {
                ans|=true;
            }
        }
        else
        {
            if(check(i+1,j,nums,0,sum)&&check(i,j-1,nums,0,sum))
            {
                ans|=1;
            }
        }
        return ans;
    }
    bool PredictTheWinner(vector<int>& nums) {
        n=nums.size();
        if(n==1)
        {
            return true;
        }
        total=accumulate(nums.begin(),nums.end(),0);
        return check(0,n-1,nums,0,0);
    }
};