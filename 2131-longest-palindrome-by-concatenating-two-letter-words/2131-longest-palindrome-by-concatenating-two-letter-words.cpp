class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> avail;
        int ans=0;
        for(auto &word:words)
        {
            string rev=word;
            reverse(rev.begin(),rev.end());
            if(avail[rev]>0)
            {
                ans+=4;
                avail[rev]--;
            }
            else
            avail[word]++;
        }
        for(auto &pr:avail)
        {
            string word=pr.first;
            int cnt=pr.second;
            if(word[0]==word[1]&&cnt>0)
            {
                ans+=2;
                break;
            }
        }
        return ans;
    }
};