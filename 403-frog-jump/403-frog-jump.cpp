class Solution {
public:
    bool canCross(vector<int>& stones) {
        map<int,set<int>> mp;
        int n=stones.size();
        mp[stones[0]].insert(1);
        for(auto pr:mp)
        {
            int currPos=pr.first;
            int pos;
            for(auto it=pr.second.begin();it!=pr.second.end();it++)
            {
                pos=currPos+*it;
                if(pos==stones[n-1])
                return true;
                if(find(stones.begin(),stones.end(),pos)!=stones.end())
                {
                    if(*it-1>0)
                    mp[pos].insert(*it-1);
                    mp[pos].insert(*it);
                    mp[pos].insert(*it+1);
                }
            }
        }
        return false;
    }
};