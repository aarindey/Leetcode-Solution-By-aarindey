class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        bool inrange=false;
        for(int i=left;i<=right;i++)
        {
            inrange=false;
            for(auto v:ranges)
            {
                if(i<=v[1]&&i>=v[0])
                {
                    inrange=true;
                    break;
                }
            }
            if(!inrange)
            return false; 
        }
        return true;
    }
};