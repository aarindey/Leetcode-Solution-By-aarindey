class Solution {
public:
    int minimumMoves(string s) {
    int c=0;
    int i=0;
    while(i<s.length())
    {
        if(s[i]=='O')
        i++;
        else
        {
            c++;
            i+=3;
        }
    }
        return c;
    }
};