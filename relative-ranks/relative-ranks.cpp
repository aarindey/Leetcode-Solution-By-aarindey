class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
     vector<string> ans;
     unordered_map<int,string> mp;
     vector<int> v=score;
     sort(v.begin(),v.end(),greater<int>());
     for(int i=0;i<v.size();i++)
     {
         if(i==0)
         mp[v[i]]="Gold Medal";
         else if(i==1)
         mp[v[i]]="Silver Medal";
        else if(i==2)
        mp[v[i]]="Bronze Medal";
         else
        mp[v[i]]=to_string(i+1);
     }
     for(int i=0;i<score.size();i++)
     {
         ans.push_back(mp[score[i]]);
     }
        return ans;
    }
};