class Solution {
public:
    bool static comp(vector<int> &a,vector<int> &b)
    {
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),comp);
        int ans=0;
        int n=pairs.size();
        int curr=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(curr<pairs[i][0])
            {
                ans++;
                curr=pairs[i][1];
            }
        }
        return ans;
    }
};

