class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        int n=stones.size();
        for(int i=0;i<n;i++)
        pq.push(stones[i]);
        while(pq.size()>1)
        {
           int x,y;
            x=pq.top();
            pq.pop();
            y=pq.top();
            pq.pop();
            int new_stone=abs(x-y);
            if(new_stone!=0)
            pq.push(new_stone);
        }
        if(pq.size()==0)
        return 0;
        else
        return pq.top();
    }
};