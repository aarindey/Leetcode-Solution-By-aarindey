class Solution {
public:
    bool static comp(pair<int,double> &a,pair<int,double> &b)
    {
        return a.first>=b.first;
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,double>> time(n);
        for(int i=0;i<n;i++)
        {
            time[i].first=position[i];
            time[i].second=(double)(target-position[i])/(1.0*speed[i]);
        }
        sort(time.begin(),time.end(),comp);
        int ans=0;
        double prevTime=0;
        for(int i=0;i<n;i++)
        {
            if(time[i].second>prevTime)
            {
                ans++;
                prevTime=time[i].second;
            }
        }
        return ans;
    }
};