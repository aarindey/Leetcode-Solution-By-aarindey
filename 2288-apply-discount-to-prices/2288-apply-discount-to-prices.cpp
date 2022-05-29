#define ll long long int
#define ld long double
class Solution {
public:
    string check(string s,int d)
    {
        int c=0;
        for(char ch:s)
        {
            if(isdigit(ch))
            {
                c++;
            }
        }
        string res="";
        if(c!=s.length()||c==0)
        return "-1";
        else
        {
            ll zz=stoll(s);
            
            ll dd=(d)*zz;
            
            ld xx=dd/100.0;
            ld rr=zz-xx;
            res=to_string(rr);
            int x=4;
            while(x--)
            res.pop_back();
        
        }
        return res;
    }
    string discountPrices(string s, int d) {
        s+=' ';
        int n=s.length();
        int left=0;
        string ans="";
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
            {
                string str=s.substr(left,i-left);
                bool ok=false;
                if(str[0]=='$')
                {
                    string z=str.substr(1);
                    string a=check(z,d);
                    if(a!="-1")
                    {
                      ans+='$';
                      ans+=a;  
                      ans+=' ';
                        ok=true;
                    }
                    else
                    {
                        ans+=str;
                        ans+=' ';
                    }
                }
                else
                {
                    if(!ok)
                    {
                        ans+=str;
                        ans+=' ';
                    }
                }
                left=i+1;
            }
        }
        ans.pop_back();
        return ans;
    }
};