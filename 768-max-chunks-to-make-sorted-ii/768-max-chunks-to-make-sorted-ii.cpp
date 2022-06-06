class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int n=arr.size();
        vector<pair<int,int>> v(n);
        //int maxi=0;
        //int ans=0;
        for(int i=0;i<n;i++)
        {
            v[i].first=arr[i];
            v[i].second=i;
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
        {
            arr[v[i].second]=i;
        }
        int maxi=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,arr[i]);
            if(maxi==i)
            {
                ans++;
            }
        }
            
        return ans;
    }
};