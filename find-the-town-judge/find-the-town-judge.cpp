class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int m=trust.size();
        if(m==1)
         return trust[0][1];
        if(n==1&&m==0)
         return 1;   
        unordered_map<int,int> mp;
        unordered_map<int,int> mp2;
        for(int i=0;i<m;i++)
        {
           mp[trust[i][1]]++;
           mp2[trust[i][0]]++;
        }
        int ans=0;
        for(auto pr:mp)
        {
            if(pr.second==n-1)
            {
                ans=pr.first;
            }   
        }
        if(ans==0||mp2.count(ans))
         return -1;
        
        return ans;    
    }
};