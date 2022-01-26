class Solution {
public:
    bool canCross(vector<int>& stones) {
        map<int, set<int>> mp;
        mp[stones[0]+1] = {1}; 
        for(int i=1;i<stones.size();i++){
            for(auto jump : mp[stones[i]]){
                mp[stones[i]+jump].insert(jump);
                mp[stones[i]+jump-1].insert(jump-1);
                mp[stones[i]+jump+1].insert(jump+1);
            }
            
        }
        if(mp[stones[stones.size()-1]].size())
        return true; 
        return false;
    }
};