class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
       int even_cnt=0;
        int odd_cnt=0;
        for(int i=0;i<position.size();i++)
        {
            if(position[i]%2==0)
                even_cnt++;
            else 
                odd_cnt++;
        }
        return min(even_cnt,odd_cnt);
    }
};