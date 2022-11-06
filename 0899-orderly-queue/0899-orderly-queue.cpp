class Solution {
public:
    string orderlyQueue(string s, int k) {
     string ans=s;
        if(k==1)
     {
            for(int i=1;i<s.length();i++)
         ans=min(ans,s.substr(i)+s.substr(0,i));
            return ans;
     }
       else
       sort(s.begin(),s.end());
        return s;
    }
};