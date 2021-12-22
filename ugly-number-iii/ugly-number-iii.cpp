// class Solution {
// public:
//     #define ll long long int
//     int nthUglyNumber(int n, int a, int b, int c) {
//         ll low=1,high=2*1e9;
//         ll A,B,C;
//         A=long(a);
//         B=long(b);
//         C=long(c);
//         while(low<high)
//         {
//             ll mid=low+(high-low)/2;
//             ll a1,b1,c1,ab,bc,ca,abc;
//             a1=(ll)mid/A;
//             b1=(ll)mid/B;
//             c1=(ll)mid/C;
//             ab=(mid*__gcd(A,B))/(A*B);
//             bc=(mid*__gcd(C,B))/(C*B);
//             ca=(mid*__gcd(A,C))/(A*C);
//             abc=(mid*__gcd(A,__gcd(B,C)))/(A*B*C);
//             ll count=a1+b1+c1-ab-bc-ca+abc;
//             if(count<n)
//             {
//                 low=mid+1;
//             }
//             else
//             high=mid;
//         }
//         return (int)low;
//     }
// };
class Solution {
public:    
   int nthUglyNumber(int k, int A, int B, int C) {
        int lo = 1, hi = 2 * (int) 1e9;
        long a = long(A), b = long(B), c = long(C);
        long ab = a * b / __gcd(a, b);
        long bc = b * c / __gcd(b, c);
        long ac = a * c / __gcd(a, c);
        long abc = a * bc / __gcd(a, bc);
        while(lo < hi) {
            int mid = lo + (hi - lo)/2;
            int cnt = mid/a + mid/b + mid/c - mid/ab - mid/bc - mid/ac + mid/abc;
            if(cnt < k) 
                lo = mid + 1;
            else
			   //the condition: F(N) >= k
                hi = mid;
        }
        return lo;
    }
};