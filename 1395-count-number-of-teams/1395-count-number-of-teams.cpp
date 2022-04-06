class Solution {
public:
    int numTeams(vector<int>& rating) {
     int ans=0;
        int n=rating.size();
        for(int i=1;i<n;i++)
        {
            int lesserLeft=0,greaterLeft=0,lesserRight=0,greaterRight=0;
            int j=0,k=n-1;
            while(j<i)
            {
                if(rating[j]<rating[i])
                {
                    lesserLeft++;
                }
                if(rating[j]>rating[i])
                {
                    greaterLeft++;
                }
                j++;
            }
            while(k>i)
            {
                if(rating[k]<rating[i])
                {
                    lesserRight++;
                }
                if(rating[k]>rating[i])
                {
                    greaterRight++;
                }
                k--;
            }
            ans+=(lesserLeft*greaterRight)+(greaterLeft*lesserRight);
        }
        return ans;
    }
};