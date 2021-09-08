class Solution {
public:
        vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++)
            v.push_back({nums[i],i});
        sort(v.begin(),v.end());
        int low=0;
        int high=v.size()-1;
        int i=0;
        int j=0;
        while(low<high)
        {
            if(v[low].first+v[high].first==target)
            {
                i=v[low].second;
                j=v[high].second;
                break;
                
            }
            if(v[low].first+v[high].first<target)
                low++;
            if(v[low].first+v[high].first>target)
                high--;
    }
        return {i,j};
    }
};