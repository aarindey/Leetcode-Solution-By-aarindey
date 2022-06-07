class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n=s.length();
        int n2=words.size();
        int len=words[0].size();
        map<string,int> mp,mp2;
        for(auto word:words)
        {
            mp[word]++;
        }
        vector<int> ans;
        for(int i=0;i<=n-n2*len;i++)
        {
            string str=s.substr(i,n2*len);
            mp2=mp;
            for(int j=0;j<n2*len;j+=len)
            {
                string str2=str.substr(j,len);
                //cout<<str2<<endl;
                mp2[str2]--;
                if(mp2[str2]==0)
                {
                    mp2.erase(str2);
                }
            }
            if(mp2.size()==0)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};