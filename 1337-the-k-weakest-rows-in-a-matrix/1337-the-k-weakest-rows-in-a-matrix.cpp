#include<bits/stdc++.h>
class comp{
  public:
  bool operator()(const pair<int,int> &a,const pair<int,int> &b)
  {
      if(a.first==b.first)
      return a.second>b.second;
      return a.first>b.first;
  }
};
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp > q;
        for(int i=0;i<mat.size();i++)
        {
            int c=0;
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==1)
                c++;
            }
            q.push({c,i});
        }
        vector<int> ans;
        while(k--)
        {
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};