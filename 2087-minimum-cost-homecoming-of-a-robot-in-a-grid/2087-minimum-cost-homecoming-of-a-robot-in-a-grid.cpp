class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
       int n=rowCosts.size();
       int m=colCosts.size();
       int sum=0;
        int a,b,p,q;
        int x,y,r,s;
        p=startPos[0];
        q=startPos[1];
        r=homePos[0];
        s=homePos[1];
        a=min(p,r);
        b=min(q,s);
        x=max(p,r);
        y=max(q,s);
        for(int i=a;i<=x;i++)
        {
            sum+=rowCosts[i];
        }
        for(int i=b;i<=y;i++)
        {
            sum+=colCosts[i];
        }
        sum-=rowCosts[p];
        sum-=colCosts[q];
        return sum;
    }
};