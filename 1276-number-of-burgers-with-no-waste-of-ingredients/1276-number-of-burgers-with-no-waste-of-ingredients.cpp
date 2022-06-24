class Solution {
public:
    vector<int> numOfBurgers(int t, int c) {
        int x=(t/2)-c;
        int y=c-x;
        if(x<0||y<0)
        return {};
        if(4*x+2*y==t)
        {
            return {x,y};
        }
        return {};
    }
};