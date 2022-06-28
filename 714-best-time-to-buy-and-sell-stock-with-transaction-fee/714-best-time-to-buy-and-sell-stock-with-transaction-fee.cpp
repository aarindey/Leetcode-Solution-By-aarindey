class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int obsp=-prices[0],ossp=0;
         int nbsp=0,nssp=0;
        int n=prices.size();
        for(int i=1;i<n;i++)
        {
            if(ossp-prices[i]>obsp)
            {
                nbsp=ossp-prices[i];
            }
            else
            {
                nbsp=obsp;
            }
            
            if(obsp+prices[i]-fee>ossp)
            {
                nssp=obsp+prices[i]-fee;
            }
            else
            {
                nssp=ossp;
            }
            ossp=nssp;
            obsp=nbsp;
        }
        return nssp;
    }
};