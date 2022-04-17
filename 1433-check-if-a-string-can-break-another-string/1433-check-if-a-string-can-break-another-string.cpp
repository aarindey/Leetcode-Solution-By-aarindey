class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
     sort(s1.begin(),s1.end());
     sort(s2.begin(),s2.end());
        int n=s1.length();
        int c1,c2,c3;
        c1=c2=c3=0;
        for(int i=0;i<n;i++)
        {
            if(s1[i]>s2[i])
            {
                c1++;
            }
            else if(s1[i]<s2[i])
            {
                c2++;
            }
            else
            {
                c3++;
            }
        }
        if(c1+c3==n||c2+c3==n)
        {
            return true;
        }
        return false;
    }
};