class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int ans=0;
        priority_queue<int> pq;
        for(auto pile:piles)
        {
            pq.push(pile);
            ans+=pile;
        }
        while(k--)
        {
            int topp=pq.top();
            pq.pop();
            ans-=topp;
            int dec=floor((double)topp/2.0);
            int newPile=topp-dec;
            ans+=newPile;
            pq.push(newPile);
        }
        return ans;
    }
};