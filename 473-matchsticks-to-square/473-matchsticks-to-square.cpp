class Solution {
public:
    bool repeatedState(int i,vector<int> side)
    {
        for(int j=0;j<i;j++)
        {
            if(side[j]==side[i])
                return true;
            
        }
        return false;
    }
    bool helper(vector<int> &match,vector<int> &side,int i)
    {
        if(i==match.size())
        {
            if(side[0]==0&&side[1]==0&&side[2]==0&&side[3]==0)
                return true;
            else
                return false;
        }
        for(int j=0;j<4;j++)
        {
            if(match[i]>side[j]||repeatedState(j,side))
            {
                continue;
            }
            side[j]-=match[i];
            if(helper(match,side,i+1))
            return true;
            side[j]+=match[i];
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum=accumulate(matchsticks.begin(),matchsticks.end(),(int)0);
        int n=matchsticks.size();
        if(sum%4!=0||n<4)
        return false;
        vector<int> side(4,sum/4);
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        return helper(matchsticks,side,0);
    }
};