class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int alice=0,bob=0;
        priority_queue<vector<int>> pq;
        int n=aliceValues.size();
        for(int i=0;i<n;i++)
        {
     pq.push({(aliceValues[i]+bobValues[i]),aliceValues[i],bobValues[i]});
        }
        bool ok=true;
        while(!pq.empty())
        {
            vector<int> v;
            v=pq.top();
            pq.pop();
            if(ok)
            {
            alice+=v[1];
            ok=false;
            }
            else
            {      
            bob+=v[2];
            ok=true;
            }
        }
        if(alice>bob)
        return 1;
        else if(bob>alice)
        return -1;
        
        return 0;
    }
};
