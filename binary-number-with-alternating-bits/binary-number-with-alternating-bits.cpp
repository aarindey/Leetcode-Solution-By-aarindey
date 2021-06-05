class Solution {
public:
    bool hasAlternatingBits(int n) {
int prev=-1;
int curr=-1;
        while(n)
        {
            curr=n&1;
            if(curr==prev)
              return false;
            prev=curr;
            n=n>>1;
        }
        return true;
    }
};