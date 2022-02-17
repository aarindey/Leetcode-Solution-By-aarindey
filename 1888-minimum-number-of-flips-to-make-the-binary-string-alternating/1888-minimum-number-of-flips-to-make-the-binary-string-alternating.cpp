class Solution {
public:
    int minFlips(string s) {
        int n2=s.length();
        string c1="",c2="";
        s=s+s;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                c1+='0';
                c2+='1';
            }else{
                c1+='1';
                c2+='0';
            }
        }
        int i=0;
        int diff1=0,diff2=0,ans=INT_MAX;
        for(int j=0;j<n;j++)
        {
            if(s[j]!=c1[j])
            {
                diff1++;
            }
            if(s[j]!=c2[j])
            {
                diff2++;
            }
            if(j-i+1>n2)
            {
                if(s[i]!=c1[i])
                {
                    diff1--;
                }
                if(s[i]!=c2[i])
                {
                    diff2--;
                }
                i++;
            }
            if(j-i+1==n2)
            {
                ans=min(ans,min(diff1,diff2));
            }
        
        }
        return ans;
    }
};