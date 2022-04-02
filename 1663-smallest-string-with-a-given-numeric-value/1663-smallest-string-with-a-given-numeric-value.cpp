class Solution {
public:
    string getSmallestString(int n, int k) {
        string s(n,'a');
        k-=n;
        for(int i=n-1;i>=0;i--)
        {
            if(k==0)
            {
                break;
            }
            if(k<25)
            {
                s[i]+=k;
                k=0;
            }
            else
            {
                s[i]+=25;
                k-=25;
            }
        }
        return s;
    }
};