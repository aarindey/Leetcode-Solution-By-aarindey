class Solution {
public:
    bool halvesAreAlike(string s) {
       string a,b;
        int n=s.length();
        a=s.substr(0,n/2);
        b=s.substr(n/2,n/2);
        int c1=0,c2=0;
        for(int i=0;i<n/2;i++)
        {
            if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'||a[i]=='A'||a[i]=='E'||a[i]=='I'||a[i]=='O'||a[i]=='U')
                c1++;
         if(b[i]=='a'||b[i]=='e'||b[i]=='i'||b[i]=='o'||b[i]=='u'||b[i]=='A'||b[i]=='E'||b[i]=='I'||b[i]=='O'||b[i]=='U')
            c2++;
            }
        if(c1==c2)
            return true;
        else
            return false;
    }
};