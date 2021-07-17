//1925. Count Square Sum Triples
class Solution {
public:
    int countTriples(int n) {
        // int c=0;
       // for(int i=1;i<=n;i++)
       // {
       //     for(int j=i;j<=n;j++)
       //     {
       //         for(int k=j;k<=n;k++)
       //         {
       //          if((i*i+j*j==k*k)||(i*i+k*k==j*j)||(j*j+k*k==i*i))
       //          c+=2;    
       //         }   
       //     }
       // }
       //  return c;

        int c = 0;
        for(int i=1 ; i<=n ; i++){
            for(int j=i+1 ; j<=n ; j++){
                int sq = ( i * i) + ( j * j);
                int r = sqrt(sq);
                if( r*r == sq && r <= n )
                    c += 2;
            }
        }
return c;
    }
};