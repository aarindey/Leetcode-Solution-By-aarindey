class Solution {
public:
    bool isMatching(string query,string pattern){
       int i=0;
       for(auto ch:query)
       {
           if(i<pattern.size()&&ch==pattern[i])
           {
               i++;
           }
           else if(ch>=65&&ch<=90)
           {
               return false;
           }
       }
      if(i==pattern.size())
      return true;
      else
      return false;
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        int n=queries.size();
        for(int i=0;i<n;i++)
        {
            ans.push_back(isMatching(queries[i],pattern));
        }
        return ans;
    }
};