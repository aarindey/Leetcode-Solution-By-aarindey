class Solution {
public:
    bool static comp(vector<int> &a,vector<int> &b)
    {
        if(a[0]==b[0])
        {
            return a[1]>b[1];
        }
        return a[0]<=b[0];
    }
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(),clips.end(),comp);
        int nextEnd=0;
        int currEnd=0;
        int n=clips.size();
        int idx=0;
        int ans=0;
        while(idx<n&&clips[idx][0]<=currEnd)
        {
            while(idx<n&&clips[idx][0]<=currEnd)
            {
                nextEnd=max(nextEnd,clips[idx][1]);
                idx++;
            }
            ans++;
            currEnd=nextEnd;
            if(currEnd>=time)
            return ans;
        }
        return -1;
    }
};