class Solution {
public:
    vector<int> constructArray(int n, int k) {
       vector<int> ans(n);
       int left=1,right=k+1;
       int idx=0;
        while(idx<k)
        {
            ans[idx++]=left++;
            ans[idx++]=right--;
        }
        if(left==right)
        {
            ans[idx++]=right;
        }
        while(idx<n)
        {
            ans[idx++]=idx+1;
        }
        return ans;
    }
};