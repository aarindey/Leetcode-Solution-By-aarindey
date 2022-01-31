class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        if(n==1)
        {
            if(minutes>0)
            return customers[0];
            else
            return 0;
        }
        vector<int> dis(n,0);
        int all=0,alldis=0;
        for(int i=0;i<n;i++)
        {
            if(grumpy[i])
            {
                dis[i]=customers[i];
                alldis+=customers[i];
            }
            if(i!=0)
            {
                dis[i]=dis[i]+dis[i-1];
            }
            all+=customers[i];
            
        }
        int maxi=dis[minutes-1];
        for(int i=1;i<=n-minutes;i++)
        {
            maxi=max(maxi,dis[i+minutes-1]-dis[i-1]);     
        }
        return all-(alldis-maxi);
    }
};