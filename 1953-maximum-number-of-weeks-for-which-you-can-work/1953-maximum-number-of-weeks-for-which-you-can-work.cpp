#define ll long long
class Solution {
public:
    long long numberOfWeeks(vector<int>& m) {
        int maxi=*max_element(m.begin(),m.end());
        ll sum=accumulate(m.begin(),m.end(),(ll)0);
        ll other=sum-maxi;
        if(other>maxi||maxi==other)
        return sum;
        else
        return 2*other+1;
    }
};