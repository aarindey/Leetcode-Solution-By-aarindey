class Solution {
public:
    void helper(vector<int> &freq,int &ans)
    {
        for(int i=0;i<26;i++)
        {
            if(freq[i])
            {
                freq[i]--;
                ans++;
                helper(freq,ans);
                freq[i]++;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        vector<int> freq(26,0);
        for(int i=0;i<tiles.size();i++)
        {
            freq[tiles[i]-'A']++;
        }
        int ans=0;
        helper(freq,ans);
        return ans;
    }
};