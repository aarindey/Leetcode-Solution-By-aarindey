class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& alice) {
        vector<int> ans;
        int maxi=INT_MIN;
        int curr;
        for(int i=1;i<4096;i++)
        {
            int num=numArrows;
            vector<int> temp(12,0);
            for(int j=11;j>=1;j--)
            {
                if(i&(1<<j))
                {
                    if(num>alice[j])
                    {
                        num-=(alice[j]+1);
                        temp[j]=(alice[j]+1);
                    }
                }
            }
            if(num>0)
            for(int j=1;j<12;j++)
            {
                if(i&(1<<j))
                {
                    temp[j]+=num;
                    break;
                }
            }
            curr=0;
            for(int i=1;i<12;i++)
            {
                if(temp[i]>alice[i])
                {
                    curr+=i;
                }
            }
            if(curr>maxi)
            {
                maxi=curr;
                ans=temp;
            }
        }
        return ans;
    }
};