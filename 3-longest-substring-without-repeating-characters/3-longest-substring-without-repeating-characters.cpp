class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int n=s.size(),left=0,right=0;
        int len=0;
        vector<int>v(256,-1);
        while(right<n)
        {
            if(v[s[right]]!=-1)
            {
                left=max(left,v[s[right]]+1);
            }
           v[s[right]]=right;
            len=max(len,right-left+1);
            right++;   
        }
        return len;
    }
};