#define ll long long int
class Solution {
public:
    bool canFit(int n,ll mid,vector<int> &b)
    {
        ll currSum=0;
        ll neededSum=mid*n;
        for(ll i=0;i<b.size();i++)
        {
            if(b[i]>=mid)
            {
                currSum+=mid;
            }
            else
            {
                currSum+=b[i];
            }
            if(currSum>=neededSum)
            {
                return true;
            }
        }
        return currSum>=neededSum;
    }
    long long maxRunTime(int n, vector<int>& b) {

        ll sum=accumulate(b.begin(),b.end(),(ll)0);
        ll high=(sum/n)+1;
        ll low=*min_element(b.begin(),b.end());
        ll ans=low;
        while(low<high)
        {
            ll mid=low+(high-low)/2;
            if(canFit(n,mid,b))
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid;
            }
        }
        return ans;
    }
};