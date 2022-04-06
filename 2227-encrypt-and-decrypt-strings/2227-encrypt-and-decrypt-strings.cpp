class Encrypter {
public:
    unordered_map<char,string> mp1;\
    vector<string> dic;
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        int n=keys.size();
        for(int i=0;i<n;i++)
        {
            mp1[keys[i]]=values[i];
        }
        dic=dictionary;
    }
    string encrypt(string word1) {
     string ans="";
        for(char ch:word1)
        {
            if(mp1.find(ch)==mp1.end())
            return "";
            ans+=mp1[ch];
        }
        return ans;
    }
    int decrypt(string word2) {
        int ans=0;
        for(auto str:dic)
        {
          if(encrypt(str)==word2)
          ans++;
        }
        return ans;
    }
};