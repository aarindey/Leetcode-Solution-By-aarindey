class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
     int n=speed.size();
        for(int i=0;i<n;i++)
        {
            dist[i]=(dist[i]-1)/speed[i];
        }
        priority_queue<int,vector<int>,greater<int> > pq(dist.begin(),dist.end());
        int i=0;
        while(i<n&&i<=pq.top())
        {
            i++;
            pq.pop();
        }
        return n-pq.size();
    }
};