class Solution{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> ans;
    if(intervals.size()==0)
    return ans;
    vector<int> newInterval;
    sort(intervals.begin(),intervals.end());
    newInterval=intervals[0];
    for(auto v:intervals)
    {
        if(v[0]<=newInterval[1])
        {
            newInterval[1]=max(v[1],newInterval[1]);
        }
        else
        {
            ans.push_back(newInterval);
            newInterval=v;
        }
    }
    ans.push_back(newInterval);
        return ans;
    }
};