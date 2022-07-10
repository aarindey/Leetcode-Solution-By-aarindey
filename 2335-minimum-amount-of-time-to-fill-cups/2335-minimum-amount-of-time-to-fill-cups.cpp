class Solution {
public:
    int fillCups(vector<int>& amount) {
        int n=amount.size();
        priority_queue<int> pq;
        for(auto &x:amount)
        {
            if(x>0)
            pq.push(x);
        }
        int ans=0;
        while(!pq.empty())
        {
            if(pq.size()!=1)
            {
                int ff,ss;
                ff=pq.top();
                pq.pop();
                ss=pq.top();
                pq.pop();
                --ss;
                --ff;
                ans++;
                if(ss!=0)
                {
                    pq.push(ss);
                }
                if(ff!=0)
                {
                    pq.push(ff);
                }   
            }
            else
            {
                ans+=pq.top();
                pq.pop();
            }
        }
        return ans;
    }
};