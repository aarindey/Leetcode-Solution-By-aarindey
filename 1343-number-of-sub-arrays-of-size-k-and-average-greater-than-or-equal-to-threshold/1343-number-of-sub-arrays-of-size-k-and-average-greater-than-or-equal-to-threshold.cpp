class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int thresholdSum=threshold*k;
        int ans=0;
        int n=arr.size();
        vector<int> prefix(n);
        prefix[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+arr[i];
        }
        int currSum=prefix[k-1];
        if(currSum>=thresholdSum)
        ans++;
        for(int i=k;i<n;i++)
        {
            currSum+=arr[i];
            currSum-=arr[i-k];
            if(currSum>=thresholdSum)
            ans++;
        }
        return ans;
    }
};