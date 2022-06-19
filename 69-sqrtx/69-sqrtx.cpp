class Solution {
public:
    int mySqrt(int x) {
        long long int min=0;
        long long int max=x;
        int ans=0;
        
        while(min<=max)
        {
           long int mid=min+(max-min)/2;
          long long int temp;
            temp=mid*mid;
            if(temp==x)
                return mid;
            else if(temp<x)
            {
                ans=mid;
                min=mid+1;
            }
            else
            {
                max=mid-1;
            }
        }
        return ans;
    }
};