class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph){
        int n=graph.size();
        if(n==0||n==1)
        return 0;
        int endMask=(1<<n)-1;
        queue<pair<int,int>> q;
        set<pair<int,int>> st;
        for(int i=0;i<n;i++)
        {
            q.push({i,1<<i});
            st.insert({i,1<<i});
        }
        int level=0;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                pair<int,int> ele=q.front();
                q.pop();
                for(auto &x:graph[ele.first])
                {
                    int mask=ele.second|(1<<x);
                    if(mask==endMask)
                    return level+1;
                    if(st.find({x,mask})==st.end())
                    {
                        q.push({x,mask});
                        st.insert({x,mask});
                    }
                }
            }
            level++;
        }
        return -1;
    }
};