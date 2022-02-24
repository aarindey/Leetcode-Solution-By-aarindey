class Solution {
public:
    bool static comp(pair<int,int> &a,pair<int,int> &b)
    {
        return a.first>b.first;
    }
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num, int useLimit) {
        unordered_map<int,int> mp;
        int n=values.size();
        int c=0,ans=0;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({values[i],labels[i]});
        }
        sort(v.begin(),v.end(),comp);
        for(int i=0;i<n;i++)
        {
            if(mp.find(v[i].second)!=mp.end())
            {
                if(mp[v[i].second]<useLimit&&c<num)
                {
                ans+=v[i].first;
                mp[v[i].second]++;
                c++;
                }
            }
            else if(c<num)
            {
                ans+=v[i].first;
                mp[v[i].second]++;
                c++;
            }
            if(c==num)
            break;
        }
        return ans;
    }
};