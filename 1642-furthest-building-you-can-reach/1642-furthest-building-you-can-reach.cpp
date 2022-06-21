class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        priority_queue<int> pq;
        int i;
        for(i=0;i<h.size()-1;i++)
        {
            if(h[i+1]-h[i]>0)
            {
                b-=(h[i+1]-h[i]);
                pq.push(h[i+1]-h[i]);
                if(b<0)
                {
                    b+=pq.top();
                    pq.pop();
                    if(l>0)
                    {
                        l--;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        return i;
    }
};