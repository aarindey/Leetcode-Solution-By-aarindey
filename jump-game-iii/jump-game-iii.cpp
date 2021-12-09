class Solution {
public:
    bool dfs(vector<int> &arr,int i,vector<bool> visited)
    {
        if(i>=arr.size())
        return false;
        if(i<0)
        return false;
        if(arr[i]==0)
        {
        return true;
        }
        if(visited[i])
        return false;
        visited[i]=true;
        return dfs(arr,i+arr[i],visited)||dfs(arr,i-arr[i],visited);
    }
    bool canReach(vector<int>& arr, int start) {
       vector<bool> visited(arr.size(),false);
       return dfs(arr,start,visited);
    }
};