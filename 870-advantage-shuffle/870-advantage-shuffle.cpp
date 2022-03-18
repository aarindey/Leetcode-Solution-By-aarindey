class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> t;
        for(auto num:nums1)
        {
            t.insert(num);
        }
        vector<int> ans;
        for(auto num:nums2)
        {
            auto upper=t.upper_bound(num);
            if(upper!=t.end())
            {
                ans.push_back(*upper);
                t.erase(upper);
            }
            else
            {
                ans.push_back(*t.begin());
                t.erase(t.begin());
            }
        }
        return ans;
    }
};