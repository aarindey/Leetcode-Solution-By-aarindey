class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k!=0)
        return false;
        int parts=n/k;
        map<int,int> mp;
        for(auto num:nums)
        {
            mp[num]++;
        }
        while(mp.size()>0)
        {
            int ff=(*mp.begin()).first;
            int z=k;
            while(z--)
            {
                if(mp.find(ff)==mp.end())
                return false;
                mp[ff]--;
                if(mp[ff]==0)
                mp.erase(ff);
                ff++;
            }
        }
        if(mp.size()==0)
        return true;
        return false;
    }
};