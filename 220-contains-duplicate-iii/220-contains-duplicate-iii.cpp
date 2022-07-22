class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& v, int k, int t) {
        
        set<long long> s;
        int n=v.size();
        vector<long long> nums(n);
        for(int i=0;i<n;i++) nums[i]=v[i];
        
        for(int i=0;i<=k && i<n;i++)
        {
            if(s.find(nums[i])!=s.end()) 
            return true;
        
            s.insert(nums[i]);
            
            auto it=s.find(nums[i]);
            
            if(it!=s.begin())
            {
                it--;
                if(abs(nums[i]-*it)<=t) 
                return true;
                it++;
            }
            
            it++;
            if(it!=s.end())
            {
                if(abs(nums[i]-*it)<=t) 
                return true;
            }
        }
        
        for(int i=k+1;i<n;i++)
        {
            s.erase(nums[i-k-1]);
            if(s.find(nums[i])!=s.end()) 
            return true;
            
            s.insert(nums[i]);
            
            auto it=s.find(nums[i]);
            
            if(it!=s.begin())
            {
                it--;
                if(abs(nums[i]-*it)<=t) 
                return true;
                it++;
            }
            
            it++;
            if(it!=s.end())
            {
                if(abs(nums[i]-*it)<=t) 
                return true;
            }
        }
        return false;   
    }
};