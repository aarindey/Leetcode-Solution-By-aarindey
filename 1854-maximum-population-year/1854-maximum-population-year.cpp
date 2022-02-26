class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int start=logs[0][0],end=logs[logs.size()-1][1];
        vector<int> line(101,0);
        for(int i=0;i<logs.size();i++)
        {
            line[logs[i][0]-1950]++;
            line[logs[i][1]-1950]--;
        }
        int maxi=line[0],idx=0;
        for(int i=1;i<line.size();i++)
        {
            line[i]=line[i]+line[i-1];
            if(line[i]>maxi)
            {
                maxi=line[i];
                idx=i;
            }
        }
        return idx+1950;
    }
};