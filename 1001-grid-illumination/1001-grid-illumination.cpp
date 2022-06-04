#define ll long long int
class Solution {
public:
    set<pair<ll,ll>> st;
    unordered_map<ll,ll> rowHash,colHash,lowerDiag,upperDiag;
    bool isvalid(int x,int y,int n)
    {
        return (x>=0&&x<n&&y>=0&&y<n);
    }
    void solve(vector<int> &ans,int row,int col,int n)
    {
        if(rowHash[row]||colHash[col]||lowerDiag[row+col]||upperDiag[n-1+col-row])
        {
            ans.push_back(1);
        }
        else
        {
            ans.push_back(0);
        }
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                int x,y;
                x=row+i;
                y=col+j;
                if(isvalid(x,y,n))
                {
                    if(st.find({x,y})!=st.end())
                    {
                        //board[x][y]=0;
                        st.erase({x,y});
                        rowHash[x]--;
                        colHash[y]--;
                        lowerDiag[x+y]--;
                        upperDiag[n-1+y-x]--;
                    }
                }
            }
        }
    }
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        vector<int> ans;
        /*
        vector<int> rowHash(n,0);
        vector<int> colHash(n,0);
        vector<int> lowerDiag(2*n-1,0);
        vector<int> upperDiag(2*n-1,0);
        */
        //vector<vector<int>> board(n,vector<int>(n,0));
        for(auto v:lamps)
        {
            if(st.find({v[0],v[1]})==st.end())
            {
            //board[v[0]][v[1]]=1;
            st.insert({v[0],v[1]});
            rowHash[v[0]]++;
            colHash[v[1]]++;
            lowerDiag[v[0]+v[1]]++;
            upperDiag[n-1+v[1]-v[0]]++;
            }
        }
        for(auto q:queries)
        solve(ans,q[0],q[1],n);
        return ans;
    }
};