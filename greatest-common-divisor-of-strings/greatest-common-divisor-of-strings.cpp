class Solution {
public:
    bool check(string str1,string str,string str2)
    {
        int l1=str1.length(),l2=str.length(),l3=str2.length();
        int k=l1/l2,k2=l3/l2;
        string s="",s2="";
        while(k--)
        {
            s+=str;
        }
        while(k2--)
        {
            s2+=str;
        }
        return (s==str1)&&(s2==str2);
    }
    string gcdOfStrings(string str1, string str2) {
        string ans="";
        string temp;
        if(str2.length()>str1.length())
        {
            temp=str1;
            str1=str2;
            str2=temp;
        }
        for(int l=1;l<=str2.length();l++)
        {
            string str=str2.substr(0,l);
            if(check(str1,str,str2))
            ans=str;
        }
    return ans;
    }
};