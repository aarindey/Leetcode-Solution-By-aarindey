class Solution {
public:
    int n;
    int shelf;
    vector<int> dp;
    int fun(vector<vector<int>> &books,int shelfWidth,int i)
    {
        if(i>=n)
        return 0;
        int curr_height=books[i][1];
        int curr_width=books[i][0];
        int curr_shelf=shelfWidth-curr_width;
        if(i==n-1)
        return curr_height;
        if(dp[i]!=-1)
        return dp[i];
        int ans=INT_MAX;
        for(int j=i+1;j<n;j++)
        {
            int height,width;
            height=books[j][1];
            width=books[j][0];
            if(width<=curr_shelf)
            {
                ans=min(ans,curr_height+fun(books,shelfWidth,j));
                curr_height=max(curr_height,height);
                curr_shelf-=width;
                ans=min(ans,curr_height+fun(books,shelfWidth,j+1));
            }
            else
            {
                ans=min(ans,curr_height+fun(books,shelf,j));
                break;
            }
        }
        return dp[i]=ans;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
       shelf=shelfWidth;
       n=books.size();
        dp.resize(1001,-1);
       return fun(books,shelfWidth,0); 
    }
};