class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> ans;
        unordered_map<int,int> mp;
        vector<int> check;
        for(int a:nums1)
        {
            if(find(check.begin(),check.end(),a)==check.end())
            {
            mp[a]++;
            check.push_back(a);
            }
        }
        check.clear();
        for(int a:nums2)
        {
            if(find(check.begin(),check.end(),a)==check.end())
            {
            mp[a]++;
            check.push_back(a);
            } 
        }
        check.clear();
        for(int a:nums3)
        {
            if(find(check.begin(),check.end(),a)==check.end())
            {
            mp[a]++;
            check.push_back(a);
            } 
        }
        for(auto pr:mp)
        {
            if(pr.second>=2)
            ans.push_back(pr.first);
        }
        return ans;
    }
};