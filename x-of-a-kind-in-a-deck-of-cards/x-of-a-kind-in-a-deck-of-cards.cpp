class Solution {
public:
    // bool hasGroupsSizeX(vector<int>& deck) {
    //     unordered_map<int,int> mp;
    //     for(int i=0;i<deck.size();i++)
    //     {
    //         mp[deck[i]]++;
    //     }
    //     int res;
    //     for(auto pr:mp)
    //     {
    //         res=__gcd(pr.second,res);
    //     }
    //     return res>1;
            bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> count;
        int res = 0;
        for (int i : deck) count[i]++;
        for (auto i : count) res = __gcd(i.second, res);
        return res > 1;
    }
    
};