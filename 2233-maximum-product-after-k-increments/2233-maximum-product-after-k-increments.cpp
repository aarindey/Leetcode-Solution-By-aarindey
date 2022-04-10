class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        long long mod=1e9+7;
        priority_queue<int,vector<int>,greater<int> > pq;
        for(auto num: nums)
        {
            pq.push(num);
        }
        bool ok=true;
        while(k--)
        {
               int ele=pq.top();
               pq.pop();
               ele++;
               pq.push(ele);
        }
        int ans=1;
        while(!pq.empty())
        {
           ans=((ans%mod)*(pq.top()%mod))%mod;
            pq.pop();
        }
    return (int)(ans%mod);
    }
};