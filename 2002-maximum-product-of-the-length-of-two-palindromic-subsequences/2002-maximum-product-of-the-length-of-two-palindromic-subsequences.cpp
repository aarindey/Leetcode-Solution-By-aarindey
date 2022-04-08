class Solution {
public:
    int ans=0;
    bool isPalin(string& s)
    {
        int i=0,j=s.length()-1;
        while(i<=j)
        {
            if(s[i]!=s[j])
            return false;
            i++;
            j--;
        }
        return true;
    }
    void dfs(string& s,string& s1,string& s2,int i)
    {
        if(i>=s.length())
        {
            if(isPalin(s1)&&isPalin(s2))
            {
                ans=max(ans,((int)s1.length())*((int)s2.length()));
            }
            return;
        }
        s1+=s[i];
        dfs(s,s1,s2,i+1);
        s1.pop_back();
        
        s2+=s[i];
        dfs(s,s1,s2,i+1);
        s2.pop_back();
        
        dfs(s,s1,s2,i+1);
    }
    int maxProduct(string s) {
        string s1="",s2="";
        int i=0;
        dfs(s,s1,s2,i);
        return ans;
    }
};