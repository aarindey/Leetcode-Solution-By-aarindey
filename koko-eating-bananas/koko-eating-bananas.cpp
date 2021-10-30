class Solution {
public:
    bool isPossible(vector<int>& piles,int speed,int h)
    {
        int time=0;
        for(int b:piles)
        {
            time+=(b/speed);
            if(b%speed)
            time++;
        }
        return time<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h){
     int low=1;
     int high=*max_element(piles.begin(),piles.end());
     int ans=high;
        if(piles.size()>h)
        return -1;
        if(piles.size()==h)
        return high;

        while(low<=high)
        {
        int mid=low+(high-low)/2;
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
    return ans;
    }
};