class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> ans;
        int n=changed.size();
        if(n%2!=0)
        return ans;
        
        map<int,int> mp;
        int c=0;
        for(int i=0;i<n;i++)
        {
        if(changed[i]==0)
        c++;    
        mp[changed[i]]++;
        }
         if(c%2!=0)
         return ans; 
        c=c/2;
        sort(changed.begin(),changed.end(),greater<int>());
        for(int i=0;i<n;i++)
        {
            if(changed[i]!=0)
            {
            if(mp.find(changed[i]*2)!=mp.end()&&mp[changed[i]*2]>0&&mp[changed[i]]>0)
            {
            mp[changed[i]]--;
            mp[changed[i]*2]--;
            ans.push_back(changed[i]);
            }
            }
        }
        while(c--)
        {
            ans.push_back(0);
        }    
        if(ans.size()==n/2)
        return ans;
        else
        {
            ans.clear();
        return ans;
            }
    }
};
// class Solution {
// public:
//     vector<int> findOriginalArray(vector<int>&nums) {
//         if(nums.size()%2!=0)return vector<int>{};
//         vector<int>res;
//         sort(nums.begin(),nums.end(),greater<int>());
//         map<int,int>mp;
//         for(int i=0;i<nums.size();i++){
//             if(mp.find(nums[i]*2)!=mp.end() and mp[nums[i]*2]!=0){
//                 res.push_back(nums[i]);
//                 mp[nums[i]*2]--;
//             }else{mp[nums[i]]++;}
//         }
//         if(res.size()!=(nums.size()/2))return vector<int>{};
//         return res;
//     }
// };