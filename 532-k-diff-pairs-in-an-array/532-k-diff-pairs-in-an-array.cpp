class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> mp;
        int c=0;
        int n=nums.size();
        set<int> st;
        for(int i=0;i<n;i++)
        {
            if((k==0&&st.find(nums[i])==st.end())||st.find(nums[i])==st.end())
            {
            if(mp.find(nums[i]+k)!=mp.end())
            {
                c++;
                if(k==0)
                st.insert(nums[i]);
            }
            if(k!=0)
            if(mp.find(nums[i]-k)!=mp.end())
            {
                c++;
            }
            }
            mp.insert(nums[i]);
            if(k!=0)
            st.insert(nums[i]);
        }
        return c;
    }
};