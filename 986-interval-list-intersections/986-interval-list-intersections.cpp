class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& l1, vector<vector<int>>& l2) {
        int n1=l1.size();
        int n2=l2.size();
        if(n1==0||n2==0)
        return {};
        int i=0,j=0;
        vector<vector<int>> ans;
        while(i<n1-1&&j<n2-1)
        {
            if(max(l1[i][0],l2[j][0])<=min(l1[i][1],l2[j][1]))
            {
                ans.push_back({max(l1[i][0],l2[j][0]),min(l1[i][1],l2[j][1])});
            }
            if(i+1<n1&&j+1<n2&&l1[i][1]<l2[j+1][0]&&l2[j][1]<l1[i+1][0])
            {
                i++;
                j++;
            }
            else if(j+1<n2&&l1[i][1]>=l2[j+1][0])
            {
                j++;
            }
            else if(i+1<n1&&l2[j][1]>=l1[i+1][0])
            {
                i++;
            }
        }
        if(j==n2-1)
        {
            for(int k=i;k<n1;k++)
            {
                if(max(l1[k][0],l2[n2-1][0])<=min(l1[k][1],l2[n2-1][1]))
                {
                   ans.push_back({max(l1[k][0],l2[n2-1][0]),min(l1[k][1],l2[n2-1][1])});
                }
            }
        }
        else if(i==n1-1)
        {
            for(int k=j;k<n2;k++)
            {
                if(max(l1[n1-1][0],l2[k][0])<=min(l1[n1-1][1],l2[k][1]))
                {
                   ans.push_back({max(l1[n1-1][0],l2[k][0]),min(l1[n1-1][1],l2[k][1])});
                }
            }
        }
        return ans;
    }
};