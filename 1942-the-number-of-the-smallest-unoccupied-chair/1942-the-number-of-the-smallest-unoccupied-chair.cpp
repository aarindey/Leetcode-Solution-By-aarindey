class Solution {
public:
    bool static comp(vector<int> &a,vector<int> &b)
    {
        if(a[0]==b[0])
        {
            return a[2]<b[2];    
        }
        return a[0]<b[0];
    }
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        for(int i=0;i<times.size();i++)
        {
            times[i].push_back(i);
        }
        sort(times.begin(),times.end(),comp);
        set<int> unoccupied;
        int n=times.size();
        int ans;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++)
        unoccupied.insert(i);
        int target=times[targetFriend][2];
        for(int i=0;i<n;i++)
        {
            while(!pq.empty()&&pq.top().first<=times[i][0])
            {
                unoccupied.insert(pq.top().second);
                pq.pop();
            }
            int position=*(unoccupied.begin());
            if(targetFriend==times[i][2])
            {
                ans=position;
                break;
            }
            unoccupied.erase(unoccupied.begin());
            pq.push({times[i][1],position});
        }
        return ans;
    }
};