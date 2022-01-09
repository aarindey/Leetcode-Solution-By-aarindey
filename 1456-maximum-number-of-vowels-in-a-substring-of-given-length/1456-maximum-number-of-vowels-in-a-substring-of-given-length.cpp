class Solution {
public:
    int maxVowels(string s, int k) {
        for(char &ch:s)
        {
            if(ch=='a'||ch=='e'|ch=='i'||ch=='o'||ch=='u')
            {
                ch='1';
            }
            else
            ch='0';
        }
        int n=s.length();
        vector<int> prefix(n,0);
        prefix[0]=s[0]-'0';
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+(s[i]-'0');
        }
        int ans=prefix[k-1];
        for(int i=0;i<n-k;i++)
        {
            ans=max(ans,prefix[i+k]-prefix[i]);
        }
        return ans;
    }
};