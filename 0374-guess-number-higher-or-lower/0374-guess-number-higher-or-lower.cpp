/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n)
    {
     int left,mid,right;
     left=1;
     right=n;
     int ans=0;
     while(left<=right)
     {
         mid=left+(right-left)/2;
         if(guess(mid)==0)
         {
             ans=mid;
             break;
         }
         else if(guess(mid)==1)
         {
             left=mid+1;
         }
         else
         {
             right=mid-1;
         }
     }
     return ans;  
    }
};