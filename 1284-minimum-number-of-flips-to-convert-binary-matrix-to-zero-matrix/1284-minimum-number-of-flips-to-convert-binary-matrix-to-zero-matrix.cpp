class Solution {
public:
    bool isvalid(int i,int j,int n,int m)
    {
        return (i>=0&&j>=0&&i<n&&j<m);
    }
    bool check(vector<vector<int>> &mat)
    {
        int c=0;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                c+=mat[i][j];
            }
        }
        return c==0;
    }
    vector<vector<int>> flip(int i,int j,vector<vector<int>> mat)
    {
        vector<int> dx={1,-1,0,0};
        vector<int> dy={0,0,1,-1};
        int n=mat.size();
        int m=mat[0].size();
        for(int k=0;k<4;k++)
        {
            int newi=i+dx[k];
            int newj=j+dy[k];
            if(isvalid(newi,newj,n,m))
            {
                mat[newi][newj]=!mat[newi][newj];
            }
        }
        return mat;
    }
    int minFlips(vector<vector<int>>& mat) {
        queue<pair<vector<vector<int>>,int>> q;
        int n=mat.size();
        int m=mat[0].size();
        if(check(mat))
        {
            return 0;
        }
        q.push({mat,0});
        set<vector<vector<int>>> st;
        st.insert(mat);
        while(!q.empty())
        {
            pair<vector<vector<int>>,int> ele=q.front();
            q.pop();
            vector<vector<int>> v=ele.first;
            int steps=ele.second;
            if(check(v))
            return steps;
            
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    vector<vector<int>> v2=flip(i,j,v);
                    v2[i][j]=!v2[i][j];
                    cout<<endl;
                    if(check(v2))
                    return steps+1;
                    if(st.find(v2)==st.end())
                    {
                        q.push({v2,steps+1});
                        st.insert(v2);
                    }
                }
            }
        }
        return -1;
    }
};