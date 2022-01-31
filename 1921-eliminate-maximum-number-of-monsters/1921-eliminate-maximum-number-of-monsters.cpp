class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
     int n=speed.size();
        for(int i=0;i<n;i++)
        {
            dist[i]=(dist[i]-1)/speed[i];
        }
        sort(dist.begin(),dist.end());
        for(int i=0;i<n;i++)
        {
            if(dist[i]<i)
                return i;
        }
        return n;
    }
};