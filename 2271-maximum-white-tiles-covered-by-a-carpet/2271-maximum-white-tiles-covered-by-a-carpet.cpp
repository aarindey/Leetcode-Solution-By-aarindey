class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(),tiles.end());
        int n=tiles.size();
        vector<int> prefix(n,0);
        for(int i=0;i<n;i++)
        {
            prefix[i]=tiles[i][1]-tiles[i][0]+1;
            if(i>0)
            {
                prefix[i]+=prefix[i-1];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int leftEnd=tiles[i][0];
            int rightEnd=tiles[i][0]+carpetLen-1;
            int l=i,r=n-1,left=i,right=i-1;
            int curr=0;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(tiles[mid][1]<=rightEnd)
                {
                    right=mid;
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
            if(right!=i-1)
            {
                curr+=prefix[right];
                if(left>0)
                curr-=prefix[left-1];
            }
            if(right+1<n)
            {
                curr+=max(0,rightEnd-tiles[right+1][0]+1);
            }
            ans=max(ans,curr);
        }
        return ans;
    }
};