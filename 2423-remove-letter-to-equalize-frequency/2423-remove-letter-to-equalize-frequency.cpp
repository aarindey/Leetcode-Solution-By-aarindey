class Solution {
public:
    bool check(vector<int> count)
    {
        sort(count.begin(),count.end());
        for(int i=0;i<=24;i++)
        {
            if(count[i]==0)
            {
                continue;
            }
            if(count[i]!=count[i+1])
            {
                return false;
            }
        }
        return true;
    }
    bool equalFrequency(string word) {
        vector<int> count(26,0);
        for(char &ch:word)
        {
            count[ch-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(count[i]==0)
            {
                continue;
            }
            count[i]--;
            if(check(count))
            {
                return true;
            }
            count[i]++;
        }
        return false;
    }
};