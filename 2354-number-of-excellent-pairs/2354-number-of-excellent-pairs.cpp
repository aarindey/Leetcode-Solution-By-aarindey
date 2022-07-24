#define ll long long 
class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> v;
        set<int> st;
        for(int &x:nums)
        {
            st.insert(x);
        }
        ll ans=0;
        for(auto it=st.begin();it!=st.end();it++)
        {
            int c=0;
            int num=*it;
            for(int j=0;j<32;j++)
            {
                if(num&(1<<j))
                {
                    c++;
                }
            }
            if(2*c>=k)
            {
                ans++;
            }
            v.push_back(c);
        }
        sort(v.begin(),v.end());
        // ll ans=0;
//         for(int i=0;i<v.size();i++)
//         {
            
//         }
        ll i,j;
        i=0;
        j=v.size()-1;
        while(i<j)
        {
            if(v[i]+v[j]<k)
            {
                i++;
                continue;
            }
            ans+=2*1ll*(j-i);
            j--;
        }
        return ans;
    }
};