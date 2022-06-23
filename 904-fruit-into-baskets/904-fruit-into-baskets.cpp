class Solution {
public:
    int n;
    bool func(vector<int> &arr,int k)
    {
        unordered_map<int,int> mpp;
        for(int i=0;i<k;i++)
        {
            mpp[arr[i]]++;
        }
        if(mpp.size()<=2)return 1;
        for(int i=k;i<n;i++)
        {
            mpp[arr[i]]++;
            mpp[arr[i-k]]--;
            if(mpp[arr[i-k]]==0)mpp.erase(arr[i-k]);
            if(mpp.size()<=2)return 1;
        }
        return 0;
    }
    
    int totalFruit(vector<int>& arr) 
    {
        n=arr.size();
        int low=0,high=n;
        int ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(func(arr,mid))
            {
                ans=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return ans;
    }
};