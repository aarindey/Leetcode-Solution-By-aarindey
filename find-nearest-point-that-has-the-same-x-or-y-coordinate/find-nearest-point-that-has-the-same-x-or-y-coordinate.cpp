class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int index=-1,smallest=INT_MAX;
    for(int i=0;i<points.size();i++)
    {
        if(x==points[i][0]||y==points[i][1])
        {
            int man=abs(x-points[i][0])+abs(y-points[i][1]);
            if(smallest>man)
            {
                smallest=man;
                index=i;
            }
            else if(smallest==man)
            {
                if(index>i)
                index=i;
            }
        }
    }
        return index;
    }
};