class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int sum1=0,sum2=0;
        for(auto &num:nums1)
        {
            sum1+=num;
        }
        for(auto &num:nums2)
        {
            sum2+=num;
        }
        if(sum1>sum2)
        {
            swap(sum1,sum2);
            swap(nums1,nums2);
        }
        int diff=abs(sum1-sum2);
        if(diff==0)
            return 0;
        vector<int> diffs;
        for(int i=0;i<nums1.size();i++)
        {
            diffs.push_back(6-nums1[i]);
        }
        for(int i=0;i<nums2.size();i++)
        {
            diffs.push_back(nums2[i]-1);
        }
        sort(diffs.begin(),diffs.end(),greater<int>());
        int ans=0;
        for(int i=0;i<diffs.size();i++)
        {
            ans++;
            diff-=diffs[i];
            if(diff<=0)
            return ans;
        }
        return -1;
    }
};