class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int,int>> pq;
        int n=apples.size(),d=1,ans=0,i=0;
        while(!pq.empty()||i<n)
        {
            if(i<n)
            {
                pq.push({-(d+days[i]),apples[i]});
            }
            i++;
            while(!pq.empty()&&-pq.top().first<=d)
            {
                pq.pop();
            }
            if(!pq.empty())
            {
                auto element=pq.top();
                pq.pop();
                element.second--;
                ans++;
                if(element.second>0)
                {
                    pq.push(element);
                }
            }
            d++;
        }
        return ans;
    }
};