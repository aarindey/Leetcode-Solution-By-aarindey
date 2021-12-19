class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n;
        sort(piles.begin(),piles.end(),greater<int>());
        int ans=0;
        int maxi=INT_MIN,maxi2=INT_MIN;
        n=piles.size()/3;
        int i=0;
        for(int j=0;j<n;j++)
        {
         ans+=piles[i+1];
         i+=2;
        }
        return ans;
    }
};