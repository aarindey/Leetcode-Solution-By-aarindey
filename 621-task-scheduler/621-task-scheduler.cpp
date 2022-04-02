class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(auto task:tasks)
        {
            mp[task]++;
        }
        priority_queue<int> pq;
        for(auto pr:mp)
        {
            pq.push(pr.second);
        }
        int ans=0;
        while(!pq.empty())
        {
            int time=0;
            vector<int> temp;
            int l=n+1;
            for(int i=0;i<l;i++)
            {
                if(!pq.empty())
                {
                temp.push_back(pq.top()-1);
                pq.pop();
                time++;
                }
            }
            for(auto ele:temp)
            {
                if(ele>0)
                pq.push(ele);
            }
            if(pq.empty())
            ans+=time;
            else
            ans+=l;
        }
       return ans;     
    }
};