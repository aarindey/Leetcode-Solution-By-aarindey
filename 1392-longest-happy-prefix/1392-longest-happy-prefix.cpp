class Solution {
public:
    string longestPrefix(string s) {
        int n=s.length();
        vector<int> v(n,0);
        int i=0;
        int j=1;
        while(j<n)
        {
            if(s[i]==s[j])
            {
                v[j]=i+1;
                i++;
                j++;
            }
            else
            {
                if(i==0)
                {
                    v[j]=0;
                    j++;
                }
                else
                {
                    i=v[i-1];
                }
            }
        }
        int sz=v.back();
        return s.substr(0,sz);
    }
};