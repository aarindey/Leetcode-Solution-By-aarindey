class Solution {
public:
    bool static comp(vector<int> &a,vector<int> &b)
    {
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        if(n==1||n==0)
        return n;
        sort(points.begin(),points.end(),comp);
        int end=points[0][1];
        int arrows=1;
        for(auto &v:points)
        {
            if(end>=v[0])
            continue;
            else
            {
                arrows++;
                end=v[1];
            }
        }
        return arrows;
    }
};