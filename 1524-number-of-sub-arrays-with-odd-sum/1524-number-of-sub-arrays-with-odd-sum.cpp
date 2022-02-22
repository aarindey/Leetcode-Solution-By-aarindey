#define ll long long
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        ll mod=1e9+7;
        int n=arr.size();
        ll sum=0;
        ll even=0,odd=0,ans=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(sum%2==0)
            {
                ans+=odd;
                even++;
            }
            else
            {
            ans+=even;
            ans++;
            odd++;
            }
        }
        return ans%mod;
    }
};