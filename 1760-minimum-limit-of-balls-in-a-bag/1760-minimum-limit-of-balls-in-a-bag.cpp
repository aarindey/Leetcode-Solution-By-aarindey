class Solution {
public:
  bool f(vector<int>& nums, int m, int k){
        int op=0;
        for(auto i:nums){
            op+= (i-1)/m;
        }
        return op<=k;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int hi = *max_element(nums.begin(),nums.end());
        int lo = 1;
        int ans = hi;
        while(lo<=hi){
            int m = (lo+hi)/2;
            if(f(nums,m,maxOperations)) 
            hi=m-1,ans=m;
            else 
            lo=m+1;
        }
        return ans;
    }
};