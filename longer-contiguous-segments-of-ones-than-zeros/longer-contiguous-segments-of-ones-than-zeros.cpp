class Solution {
public:
    bool checkZeroOnes(string s) {
        int left1=0,left2=0,max1=0,max2=0;
        for(int right=0;right<s.length();right++)
        {
            if(s[right]=='1')
            {
                while(left1<right&&s[left1]!='1')
                left1++;
                if((right-left1+1)>max1)
                 max1=right-left1+1;
            }   
            else
            {
                left1=right;
            }
        }
        
        for(int right=0;right<s.length();right++)
        {
            if(s[right]=='0')
            {
                while(left2<right&&s[left2]!='0')
                left2++;
                if((right-left2+1)>max2)
                 max2=right-left2+1;
            }   
            else
            {
                left2=right;
            }
        }
        return (max1>max2);
        }
};