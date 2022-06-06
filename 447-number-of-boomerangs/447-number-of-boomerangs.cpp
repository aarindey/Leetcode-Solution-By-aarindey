class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& p) {
        int n=p.size();
        if(n<3)
        return 0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            map<int,int> mp;
            for(int j=0;j<n;j++)
            {
                if(i==j)
                {
                    continue;
                }
                int dist=(p[i][0]-p[j][0])*(p[i][0]-p[j][0]);
                dist+=(p[i][1]-p[j][1])*(p[i][1]-p[j][1]);
                mp[dist]++;
            }
            for(auto pr:mp)
            {
               if(pr.second<=1)
               {
                   continue;
               }
               ans+=pr.second*(pr.second-1);
            }
        } 
        return ans;
    }
};