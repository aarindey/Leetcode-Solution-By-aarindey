class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
        for(int i=0;i<arr.size();i++)
        {
            pq.push({abs(arr[i]-x),arr[i]});
        }
        vector<int> v;
        while(!pq.empty()&&k>0)
        {
            v.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        sort(v.begin(),v.end());
        return v;
    }
};