class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int *minCost=new int[cost.size()+1];
        minCost[0]=0;
        minCost[1]=0;
        for(int i=2;i<=cost.size();i++)
        {
            int oneStepCost=minCost[i-1]+cost[i-1];
            int twoStepCost=minCost[i-2]+cost[i-2];
            minCost[i]=min(oneStepCost,twoStepCost);  
        }    
        int ans=minCost[cost.size()];
        delete []minCost;
        return ans;
    }
};