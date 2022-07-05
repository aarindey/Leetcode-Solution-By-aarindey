class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            st.insert(nums[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int num=nums[i]-1;
            if(st.find(num)==st.end())
            {
                int curr=nums[i];
                int c=0;
                while(st.find(curr)!=st.end())
                {
                    c++;
                    curr++;
                }
                ans=max(ans,c);
            }
        }
        return ans;
    }
};