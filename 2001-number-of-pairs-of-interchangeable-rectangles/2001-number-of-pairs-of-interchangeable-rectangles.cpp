class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long ans=0;
        int n=rectangles.size();
        unordered_map<double,long long> lookUp;
        for(int i=0;i<n;i++)
        {
            double ratio=(double)rectangles[i][0]/(1.0*rectangles[i][1]);
            if(lookUp.find(ratio)!=lookUp.end())
            {
                ans+=lookUp[ratio];
                lookUp[ratio]++;
            }
            else
            {
                lookUp[ratio]=1;
            }
        }
        return ans;
    }
};