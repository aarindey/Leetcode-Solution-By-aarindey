class Solution {
public:
    static bool comp(pair<int,int> &a,pair<int,int> &b){
        return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
     unordered_map<int,int> mp;
        vector<pair<int,int> > vec;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }   
        for(auto pr:mp)
        {
            vec.push_back(pr);
        }    
        sort(vec.begin(),vec.end(),comp);
        vector<int> ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(vec[i].first);
        }   
       return ans; 
    }
};