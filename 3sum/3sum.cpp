class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         sort(nums.begin(), nums.end()); 
           set<vector<int>> res; 
        if(nums.size() < 3) return {};
        for(int i = 0; i<nums.size()-2; i++){ 
                if( i>0 && nums[i]==nums[i-1]) continue; 
                int j = i+1; int k = nums.size()-1; 
                while(j!=k){ 
                 if( nums[i] + nums[j] +nums[k] == 0) 
                    {
                        vector<int>v; 
                     
                      v.push_back(nums[i]);  
                       v.push_back(nums[j]);  
                        v.push_back(nums[k]);
                     sort(v.begin(),v.end()); 
                        res.insert(v); 
                        
                    } 
                    if(nums[i] + nums[j] +nums[k] > 0 ) { k--; }
                    else {  j++; }
                } 
                   } 
        vector< vector< int >> ans; 
        for(auto a : res) { 
        ans.push_back(a); 
        }
        return ans;
    }
};