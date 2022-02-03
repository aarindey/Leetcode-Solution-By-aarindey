class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
     int ans=0;
        unordered_map<string,int> lookUp;
        for(auto &word:words)
        {
            lookUp[word]++;
        }
        for(auto pr:lookUp)
        {
            if(pr.first.size()>s.size())
            {
                continue;
            }
            else if(pr.first==s)
            {
                ans+=lookUp[s];
            }
            else{
                int i=0,j=0;
                string str=pr.first;
                while(i<s.length()&&j<str.length())
                {
                    if(s[i]==str[j])
                    {
                        i++;
                        j++;
                    }
                    else
                    {
                        i++;
                    }
                }
                if(j==str.length())
                {
                    ans+=lookUp[str];
                }
            }
        }
        return ans;
    }
};