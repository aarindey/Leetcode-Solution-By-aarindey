class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& m) {
        int ans=0,n=m[0].size();
        vector<int>h(n);
        for(int i=0;i<m.size();i++){
            for(int j=0;j<n;j++){
                if(m[i][j]==0)h[j]=0;
                else h[j]++;
            }
            vector<int>nh=h;
            sort(nh.begin(),nh.end());
            for(int i=0;i<n;i++)ans=max(ans,nh[i]*(n-i));
        }        
        return ans;
    }
};