class Solution {
public:
    int minOperations(string s) {
        int n=s.length();
        int way1=0,way2=0;
        for(int i=0;i<n-1;i+=2)
        {
            //way 1 with first 0 and second 1
         if((s[i]=='0'&&s[i+1]=='0')||(s[i]=='1'&&s[i+1]=='1'))
         {
           way1++;  
         }
        else if(s[i]=='1'&&s[i+1]=='0')
        {
            way1+=2;
        }
            //way 2 with first 1 and second 0
         if((s[i]=='0'&&s[i+1]=='0')||(s[i]=='1'&&s[i+1]=='1'))
         {
           way2++;  
         }
        else if(s[i]=='0'&&s[i+1]=='1')
        {
            way2+=2;
        }
           }
        if(n%2!=0)
        {
            if(s[n-1]=='0')
                way2++;
            if(s[n-1]=='1')
                way1++;
        }  
           return min(way1,way2);
    }
};