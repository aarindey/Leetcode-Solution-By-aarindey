class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int ans=INT_MAX;
        map<int,set<int> > mp;
        int n=points.size();
        for(int i=0;i<n;i++)
        {
            mp[points[i][0]].insert(points[i][1]);
        }
        
        for(auto pr1=mp.begin();pr1!=mp.end();pr1++)
        {
            if(pr1->second.size()<2)
            continue;
            for(auto pr2=pr1;pr2!=mp.end();pr2++)
            {
                if(pr2->second.size()<2)
                continue;
                if(pr1->first==pr2->first)
                continue;
                int x1,x2;
                x1=pr1->first;
                x2=pr2->first;
                for(auto y1:pr1->second)
                {
                    for(auto y2:pr2->second)
                    {
                        if(y1==y2)
                        {
                            continue;
                        } if(mp[x1].find(y2)!=mp[x1].end()&&mp[x2].find(y1)!=mp[x2].end())
                    ans=min(ans,abs(x1-x2)*abs(y1-y2));
                    }
                } 
            }
        }
        if(ans==INT_MAX)
        return 0;
        return ans;
    }
};