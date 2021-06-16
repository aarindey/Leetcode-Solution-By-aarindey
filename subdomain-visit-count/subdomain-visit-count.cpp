class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int> mp;
        vector<int> vec;
        int m=cpdomains.size();
        string s;
        for(int x=0;x<m;x++)
        {
            for(int i=0;i<cpdomains[x].size();i++)
            {
                if(cpdomains[x][i]==' ')
                {
                vec.push_back(stoi(cpdomains[x].substr(0,i)));
                 break;
                }
            }   
        }
        for(int k=0;k<m;k++)
        {
            s=cpdomains[k];
            int j=s.size()-1;
            for(int i=s.size()-1;i>=0;i--)
            {
                if(s[i]=='.'||s[i]==' ')
                {
                    mp[s.substr(i+1,j-i)]+=vec[k];
                } 
            }
        }
        vector<string> v;
        for(auto pr:mp)
        {
            v.push_back(to_string(pr.second)+" "+pr.first);
        }
        return v;
    }
};