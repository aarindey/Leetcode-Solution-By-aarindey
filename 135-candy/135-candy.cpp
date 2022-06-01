class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        map<int,int> mp;
        vector<pair<int,int> > v;
        for(int i=0;i<n;i++)
        {
            v.push_back({ratings[i],i});
        }
        sort(v.begin(),v.end());
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int idx1=-1,idx2=-1;
            int idx=v[i].second;
            if(idx>0)
            {
                idx1=idx-1;
            }
            if(idx<n-1)
            {
                idx2=idx+1;
            }
            int curr=1;
            if(idx1!=-1)
            {
                if(mp.find(idx1)!=mp.end())
                {
                    if(ratings[idx1]<ratings[idx])
                    {
                        curr=mp[idx1]+1;
                    }
                    else
                    {
                        curr=1;
                    }
                }
            }
            if(idx2!=-1)
            {
                if(mp.find(idx2)!=mp.end())
                {
                    if(ratings[idx2]<ratings[idx])
                    {
                        curr=max(curr,mp[idx2]+1);
                    }
                    else
                    {
                        curr=max(curr,1);
                    }
                }
            }
            mp[idx]=curr;
            ans+=curr;
        }
        return ans;
    }
};