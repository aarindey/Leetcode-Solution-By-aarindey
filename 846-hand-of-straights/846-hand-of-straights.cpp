class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(groupSize==1)
        return true;
        if(n%groupSize!=0)
        {
            return false;
        }
        map<int,int> mp;
        for(auto num:hand)
        {
            mp[num]++;
        }
        while(mp.size()!=0)
        {
            int curr=mp.begin()->first;
            for(int i=0;i<groupSize;i++)
            {
                if(mp.find(curr+i)==mp.end())
                {
                    return false;
                }
                mp[curr+i]--;
                if(mp[curr+i]==0)
                {
                    mp.erase(curr+i);
                }
            }
        }
        return true;
    }
};