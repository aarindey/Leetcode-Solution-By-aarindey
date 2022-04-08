class Solution {
public:
    bool static comp(pair<int,pair<string,string>> &a,pair<int,pair<string,string>> &b)
    {
        return a.first<b.first;
    }
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n=indices.size();
        int prev=-1;
        string ans="";
        int add=0;
        vector<pair<int,pair<string,string>>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({indices[i],{sources[i],targets[i]}});
        }
        sort(v.begin(),v.end(),comp);
        for(int i=0;i<n;i++)
        {
            string source=v[i].second.first,target=v[i].second.second;
            int ind=v[i].first;
            int len=source.size();
            if(ind+add>prev)
            {
            string str=s.substr(ind+add,len);
            if(str==source)
            {
                s.replace(ind+add,len,target);
                add+=(target.size()-len);
                prev=ind+add+len-1;
            }
            }
        }
        return s;
    }
};