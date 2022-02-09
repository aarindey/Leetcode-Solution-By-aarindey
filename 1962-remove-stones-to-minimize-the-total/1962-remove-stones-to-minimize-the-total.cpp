class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int ans=0;
        priority_queue<int> pq;
        for(auto pile:piles)
        {
            pq.push(pile);
        }
        while(k--)
        {
            int topp=pq.top();
            pq.pop();
            int dec=floor((double)topp/2.0);
            int newPile=topp-dec;
            pq.push(newPile);
        }
        
        while(pq.size()>0)
        {
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};