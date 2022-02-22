class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
     int ans=0,n=tickets.size();
        while(tickets[k]!=0)
        {
            for(int i=0;i<n;i++)
            {
                if(tickets[i]==0)
                continue;
                tickets[i]--;
                ans++;
                if(tickets[k]==0)
                break;
            }
        }
        return ans;
    }
};