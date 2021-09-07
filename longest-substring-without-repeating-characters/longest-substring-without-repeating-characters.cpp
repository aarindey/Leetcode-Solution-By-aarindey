class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int n=s.size(),left=0,right=0;
        int len=0;
        unordered_map<char,int> mp;
        while(right<n)
        {
            if(mp.find(s[right])!=mp.end())
            {
                left=max(left,mp[s[right]]+1);
            }
            mp[s[right]]=right;
            len=max(len,right-left+1);
             right++;   
        }
        return len;
    }
};