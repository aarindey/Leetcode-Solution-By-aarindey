class Solution {
public:
    int findLucky(vector<int>& arr) {
       unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++)
       {
           mp[arr[i]]++;
       }
        vector<int> vec;
        for(auto pr:mp)
        {
         if(pr.second==pr.first)
         {
             vec.push_back(pr.first);
         }  
        }
          if(vec.size()==0)
            return -1;
           if(vec.size()==1)
             return vec[0];
            else
            {
                int m=vec[0];
                for(int i=0;i<vec.size();i++)
                {
                    m=max(m,vec[i]);
                }
                   return m;
            }  
        return 0;
    }
};