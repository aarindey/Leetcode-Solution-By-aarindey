class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size();
        int sum=0;
        vector<int> refund;
        for(int i=0;i<n;i++)
        {
            sum+=costs[i][0];
            refund.push_back(costs[i][1]-costs[i][0]);   
        }
        sort(refund.begin(),refund.end());
        for(int i=0;i<n/2;i++)
        {
            sum+=refund[i];
        }
        return sum;
    }
};