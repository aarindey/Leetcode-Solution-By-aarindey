class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        vector<pair<char,int> > vec;
        for(auto pr:mp)
        {
            vec.push_back(pr);
        }
        sort(vec.begin(),vec.end(),comp);
        string str="";
        for(int i=0;i<vec.size();i++)
        {
            while(vec[i].second>0)
            {
            str.push_back(vec[i].first);
            vec[i].second--;
            }
        }
        return str;
    }
    bool static comp(pair<char,int> a,pair<char,int> b)
    {
        return a.second>b.second;
    }
};