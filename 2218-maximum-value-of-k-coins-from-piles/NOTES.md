class Solution {
public:
int recurse(vector<vector<int>> &piles,int k,int i,int j,int n)
{
if(i>=n)
{
return 0;
}
if(k==0)
{
return 0;
}
if(j>=piles[i].size())
{
return 0;
}
int res=0;
if(j<piles[i].size())
res=max(res,piles[i][j]+recurse(piles,k-1,j+1,i,n));
res=max(res,piles[i][j]+recurse(piles,k-1,0,i+1,n));
res=max(res,recurse(piles,k,i+1,0,n));
return res;
}
int maxValueOfCoins(vector<vector<int>>& piles, int k) {
int n=piles.size();
int ans=recurse(piles,k,0,0,n);
return ans;
}
};