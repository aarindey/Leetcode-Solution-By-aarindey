#define ll long long int
class Solution {
public:
    bool isPossible(vector<int>& piles,ll speed,ll h)
    {
        ll time=0;
        for(int b:piles)
        {
            time+=(((ll)b/speed));
            if(b%speed)
            time++;
        }
        return time<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h){
     int low=1;
     int high=*max_element(piles.begin(),piles.end());
     ll ans=high;
        if(piles.size()>h)
        return -1;
        if(piles.size()==h)
        return high;

        while(low<=high)
        {
        ll mid=low+(high-low)/2;
        if(isPossible(piles,mid,h))
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
        }
    return (int)ans;
    }
};