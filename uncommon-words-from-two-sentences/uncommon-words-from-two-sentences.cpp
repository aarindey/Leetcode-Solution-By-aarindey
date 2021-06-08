class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        unordered_map<string,int> mp;
        s1+=' ';
        s2+=' ';
        string str="";
        int j=0;
        for(int i=0;i<s1.length();i++)
        {
            if(s1[i]==' ')
            {
                str=s1.substr(j,i-j);
                mp[str]++;
                j=i+1;
            }  
        }
        j=0;
        for(int i=0;i<s2.length();i++)
        {
             if(s2[i]==' ')
            {
                str=s2.substr(j,i-j);
                mp[str]++;
                j=i+1;
            } 
        }
        for(auto pr:mp)
        {
            if(pr.second==1)
            {
                ans.push_back(pr.first);
            }   
        }
        return ans;
    }
};