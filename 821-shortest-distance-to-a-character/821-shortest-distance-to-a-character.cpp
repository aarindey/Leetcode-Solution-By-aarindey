class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> idx;
        int n=s.length();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(s[i]==c)
            {
                idx.push_back(i);
            }
        }
        int m=idx.size();
        for(int i=0;i<n;i++)
        {
            int mini=INT_MAX;
            for(int j=0;j<m;j++)
            {
                mini=min(abs(i-idx[j]),mini);
            }
            ans.push_back(mini);
        }
        return ans;
    }
};