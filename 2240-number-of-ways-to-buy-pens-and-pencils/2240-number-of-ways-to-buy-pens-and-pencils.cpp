#define ll long long int
class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        ll ans=0;
        ll n1=total/cost1;
        for(int i=0;i<=n1;i++)
        {
            ll left=total-cost1*i;
            ans+=left/cost2;
            ans++;   
        }
        return ans;
    }
};