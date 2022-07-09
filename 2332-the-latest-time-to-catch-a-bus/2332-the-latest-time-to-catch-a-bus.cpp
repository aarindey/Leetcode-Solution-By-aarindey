class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& bus, vector<int>& p, int c) {
        sort(bus.begin(),bus.end());
        sort(p.begin(),p.end());
        int n=bus.size();
        int m=p.size();
       
        set<int> s;
        for(int i=0;i<m;i++)
        s.insert(p[i]);
        int i=0,j=0;
        int ans=0;
        while(i<n&&j<m)
        {
            int count=0;
            while(j<m && count<c && p[j]<=bus[i])
            {
                j++;
                count++;
            }
            if(count<c)
            {
                int x=bus[i];
                while(s.find(x)!=s.end())
                {
                    x--;
                }
                ans=max(ans,x);
            }
            i++;
        }
        j--;
        if(i<n)
        return bus[n-1];
        while(j>=0)
        {
            if(j==0)
            {
                ans=max(ans,p[j]-1) ;
                break;
            }  
            if(p[j]==1+p[j-1])
            {
                j--;
                continue;
            }
            ans=max(ans,p[j]-1);
            break;
        }
        return ans;
    }
};