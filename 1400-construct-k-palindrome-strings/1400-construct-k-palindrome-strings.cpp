class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char,int> freq;
        for(char ch:s)
        {
            freq[ch]++;
        }
        int oddCount=0;
        for(auto pr:freq)
        {
            if(pr.second%2)
            {
                oddCount++;
            }
        }
        return oddCount<=k&&k<=s.length();
    }
};