class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int> > v(2);
        set<int> st1,st2;
        for(auto num:nums1)
        {
            st1.insert(num);
        }
        for(auto num:nums2)
        {
            st2.insert(num);
        }
        for(auto it:st1)
        {
         if(st2.find(it)==st2.end())
         {
             v[0].push_back(it);
         }
        }
        for(auto it:st2)
        {
         if(st1.find(it)==st1.end())
         {
             v[1].push_back(it);
         }
        }
        return v;
    }
};