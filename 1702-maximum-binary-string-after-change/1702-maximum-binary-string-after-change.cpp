class Solution {
public:
    string maximumBinaryString(string binary) {
       int c_zeroes=0,n=binary.size();
        for(char ch:binary)
        {
            if(ch=='0')
            c_zeroes++;
        }
        if(c_zeroes==0)
        return binary;
        string s(n,'1');
        int idx;
        for(int i=0;i<n;i++)
        {
            if(binary[i]=='0')
            {
                idx=i;
                break;
            }
        }
        idx=idx+c_zeroes-1;
        s[idx]='0';
        return s;
    }
};