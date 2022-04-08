class Solution {
public:
    int minimumBuckets(string street) {
        int n=street.size();
         size_t found = street.find("HHH");
             if(found!=string::npos)
              return -1;
         if(n==1&&street[0]=='H')
         return -1;
         else if(n==1)
             return 0;
         if(street[0]=='H'&&street[1]=='H')
         {
            return -1;
         }
         if(street[n-2]=='H'&&street[n-1]=='H')
         {
             return -1;
         }
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(street[i]=='H')
            {
                if(i+2<n&&street[i+2]=='H')
                {
                    i+=2;
                }
                    c++; 
            }
        }
        return c;
    }
};