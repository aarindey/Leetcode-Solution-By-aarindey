class Solution {
public:
    bool bfs(vector<int> &arr,int start,vector<bool> &visited)
    {
        queue<int> q;
        q.push(start);
        if(arr[start]==0)
        return true;
        visited[start]=true;
        while(!q.empty())
        {
            int idx=q.front();
            q.pop();
            if(idx-arr[idx]>=0&&!visited[idx-arr[idx]])
            {
                if(arr[idx-arr[idx]]==0)
                return true;
                visited[idx-arr[idx]]=true;
                q.push(idx-arr[idx]);
            }
            if(idx+arr[idx]<arr.size()&&!visited[idx+arr[idx]])
            {
                if(arr[idx+arr[idx]]==0)
                return true;
                visited[idx+arr[idx]]=true;
                q.push(idx+arr[idx]);
            }
        }
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
       vector<bool> visited(arr.size(),false);
       return bfs(arr,start,visited);
    }
};