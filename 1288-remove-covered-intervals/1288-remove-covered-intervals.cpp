class Solution {
public:
    bool static comp(vector<int> &a,vector<int> &b)
    {
        return a[0]<b[0];
    }
   int removeCoveredIntervals(vector<vector<int>>& v){
        int  ans=0, end=-1,begin=-1,n=v.size();
        sort(v.begin(), v.end(),comp);
        for (int i=0;i<n;i++) {
            if (v[i][0]>begin&&v[i][1]>end) {
                ++ans;
                begin=v[i][0];
            }
            end= max(end, v[i][1]);
        }
        return ans;
    }
};