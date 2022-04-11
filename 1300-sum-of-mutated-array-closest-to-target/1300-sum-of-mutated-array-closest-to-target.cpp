class Solution {
public:
    int sumation(vector<int> &arr,int mid)
    {
        int n=arr.size(),sum=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<=mid)
            {
                sum+=arr[i];
            }
            else
            {
                sum+=mid;
            }
        }
        return sum;
    }
    int findBestValue(vector<int>& arr, int target) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int low=0;
        int high=arr[n-1];
        while(low<=high)
        {
            int mid=(low+high)/2;
            int sum=sumation(arr,mid);
            if(target>sum)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        int sum_high=sumation(arr,high);
        int sum_low=sumation(arr,low);
        if(abs(target-sum_high)>abs(target-sum_low))
        {
            return low;
        }
        return high;
    }
};