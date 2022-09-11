class Solution {
public:
    int mod = 1e9+7;
    int maxPerformance(int n,vector<int> &speed,vector<int> &efficiency, int k) {    
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        v.push_back({efficiency[i],speed[i]});
        sort(v.rbegin(),v.rend());
        long long total_Speed = 0, ans = 0;
        for(int i=0;i<n;i++){
            int currEff = v[i].first;
            int currSpeed = v[i].second;
            if (pq.size() == k) {
                  total_Speed -= pq.top();
                  pq.pop();
            }
            pq.push(currSpeed); 
            total_Speed += currSpeed; 
            ans = max(ans, total_Speed * currEff);  
        }
        return ans % mod;
    }
};