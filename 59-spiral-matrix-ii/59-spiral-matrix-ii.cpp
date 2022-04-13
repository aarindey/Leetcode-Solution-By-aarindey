class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> vec( n , vector<int> (n));
        int c=0;
        int sr=0,er=n-1,sc=0,ec=n-1;
        while(sr<=er&&sc<=ec)
        {
             for(int i=sc;i<=ec;i++)
             {
                c++;
                vec[sr][i]=c;
             }
             sr++;
             if(c==(n*n))
             return vec;
             for(int i=sr;i<=er;i++)
             {
                c++;
                vec[i][ec]=c;
             }
                ec--;
             if(c==(n* n))
             return vec;
             for(int i=ec;i>=sc;i--)
             {
                c++;
                vec[er][i]=c;
             }
             er--;
             if(c==(n*n))
             return vec;
             for(int i=er;i>=sr;i--)
             {
                 c++;
                 vec[i][sc]=c;
             }
                sc++;
             if(c==(n*n))
             return vec;
        }
        return vec;
    }
};