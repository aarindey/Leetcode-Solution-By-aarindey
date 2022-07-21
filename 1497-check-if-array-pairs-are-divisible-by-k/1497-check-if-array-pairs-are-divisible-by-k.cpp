class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n=arr.size();
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            int z=arr[i]%k;
            if(z>=0)
            {
                mp[z]++;
                arr[i]=z;
            }
            else
            {
                z+=k;
                mp[z]++;
                arr[i]=z;
            }
        }
        if(mp[0]%2!=0)
        return false;
        mp.erase(0);
        for(auto &pr:mp)
        {
            if(pr.first==k-pr.first)
            {
                if(mp[pr.first]%2!=0)
                {
                    return false;
                }
            }
            else
            {
                if(mp[pr.first]!=mp[k-pr.first])
                {
                    return false;
                }
            }
        }
        return true;
    }
};