class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int x,y,r,p,q,d,count;
        vector<int> ans;
        for(int j=0;j<queries.size();j++)
        {
            x=queries[j][0];
            y=queries[j][1];
            r=queries[j][2];
            count=0;
            for(int i=0;i<points.size();i++)
            {
                p=points[i][0];
                q=points[i][1];
                d=pow((p-x),2)+pow((q-y),2);
                if(d<=pow(r,2))
                count++;
            }
            ans.push_back(count);
        }
return ans;
    }        
};