class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n=arr.size(),l=-1,r;
        for(int i=n-1;i>0;i--)
        {
            if(arr[i]<arr[i-1])
            {
                l=i-1;
                break;
            }
        }
        if(l==-1)
        return arr;
        r=l+1;
        for(int i=l+1;i<n;i++)
        {
            if(arr[i]<arr[l]&&arr[i]>arr[r])
            {
                r=i;
            }
        }
        swap(arr[l],arr[r]);
        return arr;
    }
};