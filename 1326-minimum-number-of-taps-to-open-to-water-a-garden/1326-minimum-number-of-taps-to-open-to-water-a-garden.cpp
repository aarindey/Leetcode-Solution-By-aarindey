class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> v(n+1,0);
        for(int i=0;i<ranges.size();i++)
        {
            int left=max(0,i-ranges[i]);
            int right=min(n,i+ranges[i]);
            v[left]=right;
        }
        int idx=0;
        int ans=0;
        int right=0;
        while(idx<=n)
        {
            if(right==n)
            {
                return ans;
            }
            ans++;
            int temp=right;
            while(idx<=right)
            {
                temp=max(temp,v[idx]);
                idx++;
            }
            if(right==temp)
            return -1;
            right=temp;
        }
        return ans;
    }
};