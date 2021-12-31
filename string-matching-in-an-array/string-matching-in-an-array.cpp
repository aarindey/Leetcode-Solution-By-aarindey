class Solution {
public:
    bool static comp(string &a,string &b)
    {
        return a.size()<b.size();
    }
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        vector<string> ans;
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(words[j].find(words[i])!=string::npos)
                {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};