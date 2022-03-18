class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> st;
        int nums_to_delete=n-k;
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&st.back()>nums[i]&&nums_to_delete>0)
            {
                st.pop_back();
                nums_to_delete--;
            }
            st.push_back(nums[i]);
        }
        return vector<int>(st.begin(),st.begin()+k);
    }
};