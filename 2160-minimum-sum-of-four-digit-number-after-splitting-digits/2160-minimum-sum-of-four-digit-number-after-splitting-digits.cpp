class Solution {
public:
    int minimumSum(int num) {
        int ans=0;
        vector<int> digits;
        while(num>0)
        {
            digits.push_back(num%10);
            num/=10;    
        }
        int n=digits.size();
        sort(digits.begin(),digits.end());
        int num1=0,num2=0;
        num1=10*digits[0]+digits[3];
        num2=10*digits[1]+digits[2];
        ans=num1+num2;
        return ans;
    }
};