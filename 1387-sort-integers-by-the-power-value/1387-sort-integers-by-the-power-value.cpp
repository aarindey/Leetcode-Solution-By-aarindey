class Solution {
public:
    int solve(int num,vector<int> &memo)
    {
        if(num<=1)
        return 0;
        if(memo[num]!=-1)
        return memo[num];
        if(num%2==0)
        {
            return memo[num]=1+solve(num/2,memo);
        }
        else
        {
            return memo[num]=1+solve(num*3+1,memo);
        }
        return 0;
    }
    int getKth(int lo, int hi, int k) {
        vector<int> memo(1000000,-1);
        vector<pair<int,int>> ans;
        for(int i=lo;i<=hi;i++)
        {
            ans.push_back({solve(i,memo),i});
        }
        sort(ans.begin(),ans.end());
        return ans[k-1].second;
    }
};