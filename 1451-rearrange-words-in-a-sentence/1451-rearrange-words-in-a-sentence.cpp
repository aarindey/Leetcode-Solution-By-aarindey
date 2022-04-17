class Solution {
public:
    string arrangeWords(string s) {
        s+=' ';
        int n=s.size();
        int j=0;
        vector<string> v;
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
            {
                string str=s.substr(j,i-j);
                j=i+1;
                v.push_back(str);
            }
        }
        stable_sort(v.begin(),v.end(), [](const auto &s1, const auto &s2) { return s1.length() < s2.length(); });
        string ans="";
        n=v.size();
        for(int i=0;i<n;i++)
        {
            string str=v[i];
            if(str[0]>=65&&str[0]<=90)
            {
                str[0]+=32;    
            }
            ans+=str;
            if(i!=n-1)
            ans+=' ';
        }
        ans[0]=(char)(ans[0]-32);
        return ans;
    }
};