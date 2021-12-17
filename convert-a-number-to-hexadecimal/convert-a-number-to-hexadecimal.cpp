class Solution {
public:
    string toHex(int num) {
        string HEX="0123456789abcdef";
        string ans="";
        if(num==0)
        return "0";
        unsigned int num2=(unsigned int)num;
        while(num2)
        {
            ans+=HEX[num2%16];
            num2/=16;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};