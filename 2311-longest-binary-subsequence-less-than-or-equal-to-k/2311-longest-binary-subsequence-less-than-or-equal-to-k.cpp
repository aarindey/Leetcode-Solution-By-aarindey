#define ll long long int
class Solution {
public:
    int longestSubsequence(string s, int k) {
                int n=s.size();
       
        int ans=0;
        bool ok=true;
        vector<int> pre(n,0);
       
        if(s[0]=='0')pre[0]=1;
        
        if(s[0]=='1')pre[0]=0;
       
        for(int i=1;i<n;i++)
        {
            pre[i]=pre[i-1];
            if(s[i]=='0') pre[i]++;
        }
       
        reverse(pre.begin(),pre.end());
        
        pre.push_back(0);
        
        reverse(pre.begin(),pre.end());
       
       
        for(int i=0;i<n;i++)
        {
            ll c=0;
            int l=0;
            int ind=0;
           
            for(int j=i;j<n;j++)
            {
               
                c=c*1ll*2;
                if(s[j]=='1')
                {
                    c++;
                    ok=false;
                }
           
                if(c>k)
                {
                    ind=i;
                    break;
                }
                l++;
            }
            if(!ok)
            {
                cout<<c<<endl;            
            }
            ans=max(ans,l+pre[i]);
        }
       
        return ans;
       
    }
};