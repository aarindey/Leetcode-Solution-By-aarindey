class Solution {
public:
    string addStrings(string num1, string num2) {
        string temp=num1;
        if(num2.size()>num1.size())
        {
            num1=num2;
            num2=temp;
        }
        int n=num1.size()-1,m=num2.size()-1;
        string ans="";
        int carry=0;
        int sum=0;
        while(n>=0&&m>=0)
        {
        int n1=num1[n]-'0',m1=num2[m]-'0';
        sum=n1+m1+carry;
        carry=sum/10;
        sum=sum%10;
        ans=to_string(sum)+ans;
        n--;
        m--;
        }
        while(n>=0)
        {
            int n1=num1[n]-'0';
            sum=n1+carry;
            carry=sum/10;
            sum=sum%10;
            ans=to_string(sum)+ans;
            n--;
        }
        while(m>=0)
        {
            int m1=num1[m]-'0';
            sum=m1+carry;
            carry=sum/10;
            sum=sum%10;
            ans=to_string(sum)+ans;
            m--;
        }
        if(carry==1)
        ans="1"+ans;
        return ans;
    }
};