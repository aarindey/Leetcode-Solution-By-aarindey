class Solution {
public:
    bool static comp(vector<int> &a,vector<int> &b)
    {
        return a[2]<b[2];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans(k);
        for(int i=0;i<points.size();i++)
        {
            int d=points[i][0]*points[i][0]+points[i][1]*points[i][1];
            points[i].push_back(d);
        }
        sort(points.begin(),points.end(),comp);
        for(int i=0;i<k;i++)
        {
            ans[i].push_back(points[i][0]);
            ans[i].push_back(points[i][1]);
        }
        return ans;
    }
};