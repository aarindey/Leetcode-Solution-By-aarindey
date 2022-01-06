class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
       vector<pair<int,int> > v;
       for(auto &trip:trips)
       {
           v.push_back({trip[1],trip[0]});
           v.push_back({trip[2],-trip[0]});
       }
       sort(v.begin(),v.end());
       int filledSeats=0;
       for(int i=0;i<v.size();i++)
       {
           filledSeats+=v[i].second;
           if(filledSeats>capacity)
           return false;
       }
       return true;
    }
};