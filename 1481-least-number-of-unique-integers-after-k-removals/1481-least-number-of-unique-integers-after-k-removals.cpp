class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto &x:arr)
        {
            mp[x]++;
        }
        for(auto &pr:mp)
        {
            pq.push({pr.second,pr.first});
        }
        while(k--)
        {
            pair<int,int> ele=pq.top();
            pq.pop();
            if(ele.first>1)
            {
                pq.push({ele.first-1,ele.second});
            }
        }
        return pq.size();
    }
};