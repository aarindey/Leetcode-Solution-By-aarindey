class Solution {
public:
    vector<string> printVertically(string s) {
       vector<string> ans;
       s+=' ';
       vector<string> words;
        int left=0;
        int maxi=INT_MIN;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            {
                string str=s.substr(left,i-left);
                left=i+1;
                words.push_back(str);
                maxi=max((int)maxi,(int)str.size());
            }
        }
        for(int i=0;i<maxi;i++)
        {
            string res="";
            for(int j=0;j<words.size();j++)
            {
                if(i<words[j].size())
                {
                    res+=words[j][i];
                }  
                else
                {
                    res+=' ';
                }
            }
            while(!res.empty() && isspace(*res.rbegin()))
            res.erase(res.length()-1);
            ans.push_back(res);
        }
        return ans;
    }
};