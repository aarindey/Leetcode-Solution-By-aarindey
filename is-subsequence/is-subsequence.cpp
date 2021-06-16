class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<int> check;
        int j=0;
        for(int i=0;i<t.length();i++)
        {
            if(t[i]==s[j])
            {
                check.push_back(i);
                j++;
            }
        }
        if(check.size()<s.size())
        return false;
       
        return is_sorted(check.begin(),check.end());
    }
};