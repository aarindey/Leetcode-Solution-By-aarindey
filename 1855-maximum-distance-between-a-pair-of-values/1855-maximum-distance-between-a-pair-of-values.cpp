class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n,m;
        n=nums1.size();
        m=nums2.size();
        reverse(nums2.begin(),nums2.end());
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int idx=lower_bound(nums2.begin(),nums2.end(),nums1[i])-nums2.begin();
            int idx2=m-idx-1;
            if(idx2<=i)
            {
                ans=max(ans,idx2-i);
            }
            else
            {
                ans=max(ans,abs(i-idx2));
            }
        }
        return ans;
    }
};