class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),comp);
        return arr;
    }
    static bool comp(int &a,int &b)
    {
        int c1=0,c2=0,a1=a,b1=b;
        while(a1)
        {
            c1++;
            a1=a1&(a1-1);
        }
        while(b1)
        {
            c2++;
            b1=b1&(b1-1);
        }   
        if(c1==c2)
         return a<b;
        
        return c1<c2;
    }
};