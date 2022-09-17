class Solution {
    bool check(string &s, int l, int r) {
        while(l<=r) {
            if (s[l] != s[r]) 
            return false; 
            l++;
            r--;
        }
        return true; 
    }
public:
    vector<vector<int>> palindromePairs(vector<string> words) {
        unordered_map<string,int> mp;
        unordered_map<string,int> rev;  
        for (int i = 0; i < words.size(); i++) {
            mp[words[i]] = i;
            string str=words[i]; 
            reverse(str.begin(),str.end());
            rev[str]=i;
        }
        set <vector<int>> ans;    
        for (int i=0;i<words.size();i++) {
            string s= "";  
            if (rev.find(s)!=rev.end()&&rev[s]!=i&&check(words[i],0, words[i].size()-1))
            ans.insert({i, rev[s]}); 
            for (int j=0;j<words[i].size();j++) {
                s+=words[i][j];
 if(rev.find(s)!=rev.end()&&rev[s]!=i&&check(words[i],j+1,words[i].size()-1))
                ans.insert({i, rev[s]}); 
            }
            s="";
        if(mp.find(s)!=mp.end()&&mp[s]!=i&&check(words[i],0,words[i].size()-1))
            ans.insert({mp[s], i});
            for (int j=words[i].size()-1;j>=0;j--) {
                s+=words[i][j];
                if (mp.find(s)!=mp.end()&&mp[s]!=i&&check(words[i],0,j-1))
              ans.insert({mp[s], i}); 
            }
        }
        return vector<vector<int>>(ans.begin(), ans.end()); 
    }
};