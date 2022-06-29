class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        if(n==1)
        return arr[0];
        vector<int> pre(n),post(n);
        int sum=0;
        bool neg=true;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>=0)
            {
                neg=false;
                break;
            }
        }
        int ans=*max_element(arr.begin(),arr.end());
        if(neg)
        {
            return ans;
        }
        
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            ans=max(sum,ans);   
            if(sum<0)
            {
                sum=0;
            }
            pre[i]=sum;
        }
        sum=0;
        for(int i=n-1;i>=0;i--)
        {
            sum+=arr[i];
            if(sum<0)
            {
                sum=0;
            }
            post[i]=sum;
        }
        
        
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                ans=max(post[i+1],ans);
            }
            else if(i==n-1)
            {
                ans=max(pre[i-1],ans);
            }
            else
            {
                ans=max(pre[i-1]+post[i+1],ans);
            }
        }

        return ans;
    }
};