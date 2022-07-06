class Solution {
public:
    bool check(vector<int> &v,int &m,int &k,int &x)
    {
        int bouquet=0;
        int streak=0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]<=x)
            {
                streak++;
            }
            else
            {
                if(streak>=k)
                {
                    bouquet++;
                }
                streak=0;
            }
            if(streak>=k)
            {
                bouquet++;
                streak=0;
            }
        }
        return bouquet>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(m*k>n)
        return -1;
        int low=1;
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(check(bloomDay,m,k,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};