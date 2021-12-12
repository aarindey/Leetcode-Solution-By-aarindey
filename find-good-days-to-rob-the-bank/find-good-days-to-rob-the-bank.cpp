class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& s, int time) {
        vector<int> ans;
        int n=s.size();
        if(n==0)
        return {};

        vector<int> leftInc(n,0);
        vector<int> rightInc(n,0);
        int c=0;
        for(int i=1;i<n;i++)
        {
            if(s[i-1]>=s[i])
            {
                leftInc[i]=++c;
            }
            else
            {
                leftInc[i]=0;
                c=0;
            }
        }
        c=0;
        for(int j=n-2;j>=0;j--)
        {
            if(s[j+1]>=s[j])
            {
                rightInc[j]=++c;
            }
            else
            {
                c=0;
                rightInc[j]=0;
            }
        }
        for(int i=time;i<n-time;i++)
        {
            if(leftInc[i]>=time&&rightInc[i]>=time)
            ans.push_back(i);
        }
        return ans;
    }
};