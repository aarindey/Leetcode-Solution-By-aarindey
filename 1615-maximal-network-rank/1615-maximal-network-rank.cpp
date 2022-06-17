class Solution {
public:
    bool check(vector<int> &v,int i)
    {
        for(int x:v)
        {
            if(x==i)
            return true;
        }
        return false;
    }
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> graph(n);
        vector<int> degree(n,0);
        for(auto road:roads)
        {
            graph[road[0]].push_back(road[1]);
            graph[road[1]].push_back(road[0]);
            degree[road[0]]++;
            degree[road[1]]++;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                break;
                if(check(graph[i],j))
                {
                    ans=max(ans,degree[i]+degree[j]-1);
                }
                else
                {
                    ans=max(ans,degree[i]+degree[j]);
                }
            }
        }
    return ans;
    }
};