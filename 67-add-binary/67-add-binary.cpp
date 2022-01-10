class Solution {
public:
    string addBinary(string a, string b) {

        if(a.length()>b.length())
        {
            while(a.length()!=b.length())
            b='0'+b;
        }
         else if(a.length()<b.length())
        {
            while(a.length()!=b.length())
            a='0'+a;
        }
        int i=a.length()-1,j=b.length()-1;
        string ans="";
        bool carry=false;
        while(i>=0&&j>=0)
        {
            if(!carry)
            {
                if((a[i]=='1'&&b[j]=='0')||(a[i]=='0'&&b[j]=='1'))
                ans='1'+ans;
                else if(a[i]=='0'&&b[j]=='0')
                ans='0'+ans;
                else
                {
                ans='0'+ans;
                carry=true;
                }
               }
            else
            {
                if((a[i]=='1'&&b[j]=='0')||(a[i]=='0'&&b[j]=='1'))
                {
                ans='0'+ans;
                carry=true;
                }
                else if(a[i]=='0'&&b[j]=='0')
                {
                ans='1'+ans;
                carry=false;
                }
                else
                {
                ans='1'+ans;
                carry=true;
                } 
            }
            i--;
            j--;
        }
        if(carry)
        ans='1'+ans;   
        return ans;
    }
};