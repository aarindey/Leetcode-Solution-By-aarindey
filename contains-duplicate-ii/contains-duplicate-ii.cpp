class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int> > mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]].push_back(i);
        }   
        for(auto pr: mp)
        {
            if(pr.second.size()>1)
            {
                sort(pr.second.begin(),pr.second.end());
            for(int i=0;i<pr.second.size()-1;i++)
            {
                if(abs(pr.second[i]-pr.second[i+1])<=k)
                   return true; 
            }
            }    
        }
        return false;
    }
};