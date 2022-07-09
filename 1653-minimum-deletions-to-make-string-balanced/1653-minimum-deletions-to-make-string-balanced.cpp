class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.length();
        // if(n==1)
        // return 0;
        vector<int> preB(n,0);
        vector<int> sufA(n,0);
        if(s[0]=='b')
        {
            preB[0]=1;
        }
        if(s[n-1]=='a')
        {
            sufA[n-1]=1;
        }
        for(int i=1;i<n;i++)
        {
            preB[i]=preB[i-1]+(s[i]=='b');
        }
        for(int i=n-2;i>=0;i--)
        {
            sufA[i]=sufA[i+1]+(s[i]=='a');
        }
        int ans=sufA[0];
        for(int i=0;i<n;i++)
        {
            if(i+1<n)
            ans=min(ans,preB[i]+sufA[i+1]);
            else
            ans=min(ans,preB[i]);
        }
        return ans;
    }
};