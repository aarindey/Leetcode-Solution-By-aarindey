class Solution {
public:
    bool reorderedPowerOf2(int n){
        vector<int> countDig,countDigPos;
        countDig=count(n);
        for(int i=0;i<31;i++)
        {
            countDigPos=count(1<<i);
            if(countDig==countDigPos)
            return true;
        }
        return false;
    }
    vector<int> count(int n)
    {
        vector<int> v(10,0);
        while(n>0)
        {
            v[n%10]++;
            n/=10;
        }
        return v;
    }
};