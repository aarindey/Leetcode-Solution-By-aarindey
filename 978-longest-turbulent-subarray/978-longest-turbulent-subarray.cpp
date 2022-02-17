class Solution {
public:
    bool isTurbulant(vector<int> &arr,int i)
    {
        return (arr[i-1]>arr[i]&&arr[i+1]>arr[i])||(arr[i-1]<arr[i]&&arr[i+1]<arr[i]);
    }
    int maxTurbulenceSize(vector<int>& arr) {
       int n=arr.size();
        if(n<=1)
        return n;
        bool same=true;
        for(int i=1;i<n;i++)
        {
            if(arr[i-1]!=arr[i])
                same=false;
        }
        if(same)
        return 1;
        int start=0,end=0,ans=1;
        while(start+1<n)
        {
            while(arr[start]==arr[start+1])
            {
                start++;
                continue;
            }
            end=start+1;
            while(end+1<n&&isTurbulant(arr,end))
            {
                end++;
            }
            ans=max(ans,end-start+1);
            start=end;
        }
        return ans;
    }
};