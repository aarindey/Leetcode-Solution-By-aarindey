class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> mp;
        for(char ch:t)
        mp[ch]++;
        for(char ch:s)
        mp[ch]--;
        int sum=0;
        for(auto pr:mp)
        {
            if(pr.second<0)
            sum+=abs(pr.second);
        }
        return sum;
    }
};