class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
       vector<int> p(n,0);
       int curr;
        curr=rounds[0]-1;
        p[curr]++;
        for(int i=0;i<rounds.size();i++)
        {
            while(curr!=rounds[i]-1)
            {
                curr++;
                curr%=n;
                p[curr]++;
            }
        }
        int maxi=*max_element(p.begin(),p.end());
        vector<int> ans;
        for(int i=0;i<p.size();i++)
        {
            if(maxi==p[i])
            {
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};