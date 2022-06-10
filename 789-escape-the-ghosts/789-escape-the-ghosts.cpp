class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int dis=abs(target[0])+abs(target[1]);
        for(auto g:ghosts)
        {
            int gDis=abs(g[1]-target[1])+abs(g[0]-target[0]);
            if(gDis<=dis)
            {
                return false;
            }
        }
        return true;
    }
};