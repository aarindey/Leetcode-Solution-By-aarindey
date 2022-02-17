class Solution {
public:
    int maximumSwap(int num) {
        vector<int> digits;
        int maxi=INT_MIN;
        vector<int> maxArray;
        int i=0,idx;
        while(num>0)
        {
            digits.push_back(num%10);
            if(num%10>maxi)
            {
            maxi=num%10;
            idx=i;
            }
            maxArray.push_back(idx);
            num/=10;
            i++;
        }
        int n=digits.size();
        
        for(int i=n-1;i>=0;i--)
        {
         if(digits[maxArray[i]]!=digits[i])
         {
           swap(digits[maxArray[i]],digits[i]);
           break;
         }
        }
        num=0;
        for(int i=n-1;i>=0;i--)
        {
            num=num*10+digits[i];
        }
        return num;
    }
};