class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
        int m=-1,n=0;
        for(auto pr:mp)
        {
          if(pr.second>m)
          {
              m=pr.second;
              n=pr.first;
          } 
        }
        return n;
    }
};