class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int ans=1;
        int n=pairs.size();
        vector<int> t;
        t.push_back(pairs[0][1]);
 
        for(int i=1;i<n;i++)
        {
            int idx=lower_bound(t.begin(),t.end(),pairs[i][0])-t.begin();
            if(idx==t.size())
            {
                t.push_back(pairs[i][1]);
            }
            else
            {
                if(t[idx]>pairs[i][1])
                t[idx]=pairs[i][1];
            }
        }
        return t.size();
    }
};

