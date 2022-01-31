class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n=nums.size();
        deque<int> dq;
        for(int i=0;i<n;i++)
        {
            if(!dq.empty()&&i-k==dq.front())
                dq.pop_front();
             while(!dq.empty()&&nums[i]>nums[dq.back()])
             {
                 dq.pop_back();
             }
             dq.push_back(i);
            if(i>=k-1)
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};