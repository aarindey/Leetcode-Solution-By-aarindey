class Solution {
public:
    string capitalize(string s)
    {
        string res="";
        if(s.length()==1)
        {
            if(s[0]>=65&&s[0]<=90)
            {
                res+=(s[0]+32);
            }
            else
            res+=s[0];
            return res;
        }
        else if(s.length()==2)
        {
            if(s[0]>=65&&s[0]<=90)
            {
                res+=(s[0]+32);
            }
            else
            res+=s[0];
            if(s[1]>=65&&s[1]<=90)
            {
                res+=(s[1]+32);
            }
            else
            res+=s[1];
        }
        else
        {
            
            for(int i=0;i<s.length();i++)
            {
                if(i==0)
                {
                    if(!(s[i]<=90&&s[i]>=65))
                    {
                        res+=(s[i]-32);
                    }
                    else
                    res+=s[i];
                }
                else
                {
                    if(s[i]<=90&&s[i]>=65)
                    {
                        res+=(s[i]+32);
                    }
                    else
                    {
                        res+=s[i];
                    }
                } 
            }
        }
        return res;
    }
    string capitalizeTitle(string title) {
        title+=' ';
        int n=title.size();
        int left=0;
        string ans="",str;
        for(int i=0;i<n;i++)
        {
            if(title[i]==' ')
            {
                str=title.substr(left,i-left);
                left=i+1;
                ans+=capitalize(str);
                ans+=' ';
            }
        }
        ans.pop_back();
        return ans;
    }
};