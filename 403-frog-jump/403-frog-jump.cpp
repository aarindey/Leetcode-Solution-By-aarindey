class Solution {
public:
    bool canCross(vector<int>& stones) {
        map<int, set<int>> m;
        m[stones[0]+1] = {1}; 
        for(int i =1;i<stones.size();i++){
            for(auto jump : m[stones[i]]){
                m[stones[i]+jump].insert(jump);
                m[stones[i]+jump-1].insert( jump-1);
                m[stones[i]+jump+1].insert( jump+1);
            }
            
        }
        if(m[(stones[stones.size()-1])].size())
        return true; 
        return false;
    }
};