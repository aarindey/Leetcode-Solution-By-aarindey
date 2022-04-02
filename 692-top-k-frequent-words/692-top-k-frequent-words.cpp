class Solution {
public:
    struct comp{
    bool operator()(pair<int,string> const& p1, pair<int,string> const& p2)
    {
        if(p1.first!=p2.first)
        return p1.first < p2.first;
        else
        {
            return p1.second>p2.second;
        }
    }
};
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        priority_queue<pair<int,string>,vector<pair<int,string> >,comp > pq;
        for(auto word:words)
        {
            mp[word]++;
        }
        for(auto pr:mp)
        {
            pq.push({pr.second,pr.first});
        }
        vector<string> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            k--;
            pq.pop();
            if(k==0)
            break;
        }
        return ans;
    }
};