class Solution {
public:
    bool isPowerOfThree(int n) {
        for(int i=0;i<=n/3;i++)
        {
            if(pow(3,i)==n)
             return true;
            if(pow(3,i)>n)
              break;  
        }   
        return false;
    }
};