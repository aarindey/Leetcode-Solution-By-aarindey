class Solution {
public:
int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int max=0,sum=0;
        for(int i=1;i<n;i++)
        {
            sum=sum+(prices[i]-prices[i-1]);
            if(sum<0) sum=0;
            if(max<sum) max=sum;
        }
        return max;
    }
};