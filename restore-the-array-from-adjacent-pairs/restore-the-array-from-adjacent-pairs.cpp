class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs)
    {
        vector<int> ans;
        unordered_map<int,vector<int> > mp;
        for(auto &pair:adjacentPairs)
        {
        mp[pair[0]].push_back(pair[1]);
        mp[pair[1]].push_back(pair[0]);
        }
        int src;
        for(auto pr:mp)
        {
            if(pr.second.size()==1)
            {
                src=pr.first;
                break;
            }
        }
        queue<int> q;
        unordered_set<int> visited;
        q.push(src);
        while(!q.empty())
        {
            int ele=q.front();
            ans.push_back(ele);
            visited.insert(ele);
            q.pop();
            for(auto &x:mp[ele])
            {
                if(visited.find(x)==visited.end())
                {
                    q.push(x);
                }
            }
        }
        
        return ans;
    }
};