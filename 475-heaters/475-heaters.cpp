#define ll long long int
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        ll n1=houses.size();
        ll n2=heaters.size();
        sort(heaters.begin(),heaters.end());
        
        ll maxi=INT_MIN;
        for(ll i=0;i<n1;i++)
        {
            ll x=houses[i];
            ll j=lower_bound(heaters.begin(),heaters.end(),x)-heaters.begin();
            ll x1=INT_MAX;
            if(j>0)
            {
                x1=(ll)abs(x-heaters[j-1]);
            }
            if(j<n2)
            {
                x1=min(x1,(ll)abs(x-heaters[j]));
            }
            if(j<n2-1)
            {
                x1=min(x1,(ll)abs(x-heaters[j+1]));
            }
            cout<<x1<<endl;
            maxi=max(maxi,x1);
        }
        return maxi;
    }
};