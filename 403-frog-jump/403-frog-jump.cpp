class Solution {
public:
    bool canCross(vector<int>& stones) {
//      using map that stores number and the lenghts of jumps we took to reach there
//         for eg m[3] = {2} this means we reached 3 by jumping with k units. we don't care where we jumped from, we just know,from 3 we can go to 3+2-1, 3+2,3+2+1 points. we store corresponding jumplengths for these numbers too. 
//         at the end we check the last element, if we were able to reach it, the jump lenght wd be stored so return true;
        
        unordered_map<int, unordered_set<int>> m;
        m[stones[0]+1] = {1}; //becaause from 0th postion we can jump by only 1 unit
        for(int i =1;i<stones.size();i++){
            for(auto jump : m[stones[i]]){
//                 types of jumps we took to reach stones[i],
                // for eg m[4] = {2,3} that means we can jump with k =2 and k=3 
                m[stones[i]+jump].insert(jump);
                m[stones[i]+jump-1].insert( jump-1);
                m[stones[i]+jump+1].insert( jump+1);
            }
            
        }
        if(m[(stones[stones.size()-1])].size())
            return true; //means we somehow jumped to the end stone
        return false;
    }
};