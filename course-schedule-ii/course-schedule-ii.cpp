class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
     vector<vector<int>> graph(numCourses);
     vector<int> indegree(numCourses);
     for(auto &x:prerequisites)
     {
         graph[x[1]].push_back(x[0]);
         indegree[x[0]]++;
     }
     vector<int> ans;
     queue<int> q;
     for(int i=0;i<numCourses;i++)
     {
         if(indegree[i]==0)
         {
             q.push(i);
         }
     }
    while(!q.empty())
    {
        int ele=q.front();
        q.pop();
        ans.push_back(ele);
        for(auto &z:graph[ele])
        {
            indegree[z]--;
            if(indegree[z]==0)
            q.push(z);
        }
    }
    if(ans.size()==numCourses)
    return ans;
    else
    return {};
    }
};