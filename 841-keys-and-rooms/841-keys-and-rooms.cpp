class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(0);
        while(!q.empty())
        {
            int ele=q.front();
            vis[ele]=true;
            q.pop();
            for(auto v:rooms[ele])
            {
                if(!vis[v])
                {
                q.push(v);
                }
            }
        }
        return (find(vis.begin(),vis.end(),false)==vis.end());
    }
};