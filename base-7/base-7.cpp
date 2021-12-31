class Solution {
public:
    string convertToBase7(int num) {
        string ans="";
        bool neg=false;
        if(num==0)
        return "0";
        if(num<0)
        {
        neg=true;
        num=-num;
        }
        while(num)
        {
            int rem=num%7;
            ans+=to_string(rem);
            num/=7;
        }
        reverse(ans.begin(),ans.end());
        if(neg)
        {
            return '-'+ans;
        }
        return ans;
    }
};