class Solution {
public:
    int minCost(string s, vector<int>& time) {
       int n=s.size();
        int ans=0;
        bool ok;
       for(int i=1;i<n;i++)
       {
           ok=false;
           vector<int> v;
           v.push_back(time[i-1]);
            while(s[i-1]==s[i])
            {
                v.push_back(time[i]);
                i++;
                ok=true;
            }
            if(ok)
            {
            sort(v.begin(),v.end());
            i--;
            for(int k=0;k<v.size()-1;k++)
            ans+=v[k];
            }
       }
        return ans;
    }
};