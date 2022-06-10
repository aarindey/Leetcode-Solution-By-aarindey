class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int> mp;
        int ans=0;
        for(auto a:answers)
        {
            mp[a]++;
        }
        for(auto pr:mp)
        {
            if(pr.first==0)
            ans+=pr.second;
            else
            {
                int d=pr.second/(pr.first+1);
                int r=pr.second%(pr.first+1);
                ans+=d*(pr.first+1);
                if(r>0)
                {
                    ans+=pr.first+1;
                }   
            }
        }
        return ans;
    }
};