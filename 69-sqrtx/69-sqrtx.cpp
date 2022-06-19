#define ll long long int
class Solution {
public:
    int mySqrt(int x) {
        ll low=0;
        ll high=x;
        ll ans;
        while(low<=high)
        {
            ll mid=low+(high-low)/2;
            ll z=mid*mid;
            if(z==x)
            return mid;
            else if(z<x)
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return (int)ans;
    }
};