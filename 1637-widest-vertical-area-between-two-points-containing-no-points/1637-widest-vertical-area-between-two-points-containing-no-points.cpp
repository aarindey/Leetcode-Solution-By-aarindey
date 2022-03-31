class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> x;
        for(auto point:points)
        {
            x.push_back(point[0]);
        }
        sort(x.begin(),x.end());
        int maxi=INT_MIN;
        for(int i=1;i<x.size();i++)
        {
            maxi=max(maxi,x[i]-x[i-1]);
        }
        return maxi;
    }
};