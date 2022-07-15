class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n=nums.size();
        vector<int> even(n,0);
        vector<int> odd(n,0);
        int evenSum=0,oddSum=0;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                evenSum+=nums[i];
            }
            else
            {
                oddSum+=nums[i];
            }
            even[i]=evenSum;
            odd[i]=oddSum;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                evenSum=odd[n-1];
                oddSum=even[n-1]-nums[i];
            }
            else
            {
                evenSum=even[i-1]+odd[n-1]-odd[i];
                oddSum=odd[i-1]+even[n-1]-even[i];
            }
            if(evenSum==oddSum)
            ans++;
        }
        return ans;
    }
};