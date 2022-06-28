class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // obsp = old bought state profit
        // ossp = old sold state profit
        // nbsp = new bought state profit
        // nssp = new sold state profit
        int obsp=-prices[0],ossp=0;
         int nbsp=0,nssp=0;
        int n=prices.size();
        for(int i=1;i<n;i++)
        {
            nbsp=max(ossp-prices[i],obsp);
            nssp=max(obsp+prices[i]-fee,ossp);
            ossp=nssp;
            obsp=nbsp;
        }
        return nssp;
    }
};