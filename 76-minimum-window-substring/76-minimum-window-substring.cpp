class Solution {
public:
    string minWindow(string s, string t) {
     string ans="";
        map<char,int> mp1;
        int matchCount=0,desiredmatchCount=t.size();
        if(s==t)
        return s;
        for(char ch:t)
        {
            mp1[ch]++;
        }
        int n=s.size();
        map<char,int> mp2;
        int i=0,j=0;
        while(true)
        {
            bool check1=false,check2=false;
            //acquire
            while(j<n&&matchCount<desiredmatchCount)
            {
                mp2[s[j]]++;
                if(mp1.count(s[j])>0&&mp2[s[j]]<=mp1[s[j]])
                matchCount++;    
                j++;
                check1=true;
            }
            //release and collect answer
            while(i<j&&matchCount==desiredmatchCount)
            {
                string pans=s.substr(i,j-i);
                if(ans.size()==0||pans.size()<ans.size())
                {
                    ans=pans;
                }
                mp2[s[i]]--;
                if(mp1.count(s[i])>0&&mp1[s[i]]>mp2[s[i]])
                matchCount--;
                i++;
                check2=true;
            }
            if(!check1&&!check2)
            break;
        }
        return ans;
    }
};