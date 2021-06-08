class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int i;
        vector<int> nums;
        i=m;
        while(i<(m+n))
        {
            nums1[i]=nums2[i-m];
            i++;
        }
        sort(nums1.begin(),nums1.end());
    }
};