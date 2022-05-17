class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
     int n=arr.size();
     vector<int> prefix(n,0);
        prefix[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]^arr[i];
        }
        vector<int> ans(queries.size(),0);
        int c=0;
        for(auto query:queries)
        {
            if(query[0]==0)
            {
                ans[c]=prefix[query[1]];
            }
            else
            {
                ans[c]=prefix[query[1]]^prefix[query[0]-1];
            }
            c++;
        }
        return ans;
    }
};