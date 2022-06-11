#define ll long long int
#define ld long double
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& p, long long success) {
        sort(p.begin(),p.end());
        ll n=p.size();

        vector<int> ans;
        for(int x:spells)
        {
            ll up=ceil((success)/(1.0*x));
            ll idx=lower_bound(p.begin(),p.end(),up)-p.begin();
            if(idx==n)
            {
                ans.push_back(0);
            }
            else
            ans.push_back(n-idx);
        }
        return ans;
    }
};