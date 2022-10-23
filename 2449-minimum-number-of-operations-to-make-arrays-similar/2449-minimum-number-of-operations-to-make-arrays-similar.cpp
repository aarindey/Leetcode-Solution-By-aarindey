class Solution {
#define ll long long int
    public:
    long long makeSimilar(vector<int>& n, vector<int>& t) {
        sort(n.begin(),n.end());
        sort(t.begin(),t.end());
        ll ans=0;
        ll z=n.size();
        vector<ll>  en,on,et,ot;
        
        for(ll i=0;i<z;i++)
        {
            if(t[i]%2==0)
            {
               et.push_back(t[i]); 
            }
            else
            {
                ot.push_back(t[i]);
            }
            if(n[i]%2==0)
            {
                en.push_back(n[i]);   
            }
            else
            {
                on.push_back(n[i]);
            }
        }
        ll maxi=0;
        for(ll i=0;i<en.size();i++)
        {
            ans+=abs(en[i]-et[i])/2;
            maxi=max(maxi,abs(en[i]-et[i])/2);
        }
        for(ll i=0;i<on.size();i++)
        {
            ans+=abs(on[i]-ot[i])/2;
            maxi=max(maxi,abs(on[i]-ot[i])/2);
        }
        if(ans/2<maxi)
        return maxi;
        return ans/2;
    }
};