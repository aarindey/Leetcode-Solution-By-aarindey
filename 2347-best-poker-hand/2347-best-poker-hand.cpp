class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        map<int,vector<int>> mp;
        int n=ranks.size();
        bool flush=false;
        bool three,pair;
        three=pair=false;
        map<char,int> mp2;
        for(auto ch:suits)
        {
            mp2[ch]++;
            if(mp2[ch]==5)
            return "Flush";
        }
        for(int i=0;i<5;i++)
        {
            mp[ranks[i]].push_back(suits[i]);
            if(mp[ranks[i]].size()==2)
            {
                pair=true;
            }
            if(mp[ranks[i]].size()==3)
            {
                three=true;
            }
            if(mp[ranks[i]].size()==5)
            {
                flush=true;
            }
        }
        if(flush)
        {
            return "Flush";
        }
        else if(three)
        {
            return "Three of a Kind";
        }
        else if(pair)
        {
            return "Pair";
        }
        else
        return "High Card";
    }
};