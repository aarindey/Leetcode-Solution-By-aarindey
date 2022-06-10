class Solution {
public:
    bool check(map<char,int> &mp,map<char,int> word2)
    {
        char ch='a';
        while(ch!='z'+1)
        {
            if(mp.find(ch)==mp.end()&&word2.find(ch)!=word2.end())
            {
                return false;
            }
            else if(mp.find(ch)!=mp.end()&&word2.find(ch)!=word2.end())
            {
                if(word2[ch]>mp[ch])
                {
                    return false;
                }
            }
            ch++;
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        map<char,int> word2;
        for(auto word:words2)
        {
            map<char,int> temp;
            for(char ch:word)
            {
                temp[ch]++;
                word2[ch]=max(word2[ch],temp[ch]);
            }
        }
       for(auto w1:words1)
       {
           map<char,int> mp;
           for(auto ch:w1)
           {
               mp[ch]++;
           }

           if(check(mp,word2))
           {
               ans.push_back(w1);
           }

       }
    return ans;
    }
};