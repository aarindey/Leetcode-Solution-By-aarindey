class Solution {
public:
    int binaryGap(int n) {
        vector<int> vec;
        int res=0,d=0,prev=-1,i=0;
        while(n>0)
        {
            if(n%2==1&&prev>=0)
            {    
               res=max(res,i-prev);
                prev=i;
            }
            if(n%2==1)
             prev=i;   
            vec.push_back(n%2);
            i++;
            n=n/2;
        }
        return res;
    }
};