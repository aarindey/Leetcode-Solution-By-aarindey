class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
       map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int x,y;
 for(int i=1;i<=nums.size();i++)
 {
     if(mp.find(i)!= mp.end())
     {
         if(mp.find(i)->second==2)
         x=i;
     }
     else
      y=i;
 }
        return {x,y};
    }
};