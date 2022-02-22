class Solution {
public:
    int titleToNumber(string columnTitle) {
        reverse(columnTitle.begin(),columnTitle.end());
        int value=0; 
        for(int i=0;i<columnTitle.size();i++)
        {
            int num=columnTitle[i]-'A'+1;
            value+=(pow(26,i)*num);
        }
        return value;
    }
};