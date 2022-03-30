class Solution {
public:
    int helper(vector<int> &vec,int n)
    {
        int maxi=vec[0],mini=vec[0];
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,vec[i]);
            mini=min(mini,vec[i]);
        }
        return maxi-mini;
    }
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        vector<int> sum1(n),sum2(n),diff1(n),diff2(n);
        for(int i=0;i<n;i++)
        {
            sum1[i]=arr1[i]+arr2[i]+i;
            diff1[i]=arr1[i]-arr2[i]+i;
            sum2[i]=arr1[i]+arr2[i]-i;
            diff2[i]=arr1[i]-arr2[i]-i;
        }
        return max(max(helper(sum1,n),helper(sum2,n)),max(helper(diff1,n),helper(diff2,n)));
    }
};