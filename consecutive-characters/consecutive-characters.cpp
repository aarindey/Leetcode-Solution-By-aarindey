class Solution {
public:
    int maxPower(string s) {
        unordered_map<char,int> mp;
        int mx=0;
        int left=0;
        int c;
        string sub="";
        for(int i=0;i<s.length();i++)
        {   c=0;
            while(s[left]!=s[i])
            {
                left++;
            }
         sub=s.substr(left,i-left+1);
      if(sub.length()>mx)
      {
          mx=sub.length();
      }
            }
        return mx;
    }
};