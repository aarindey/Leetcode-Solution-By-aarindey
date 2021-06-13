class Solution {
public:
    int countOdds(int low, int high) {
   int count=0;
        if(low%2!=0)
        for(int i=low;i<=high;i+=2)
        {
            count++;
        }   
        else
        {
            low++;
               for(int i=low;i<=high;i+=2)
        {
            count++;
        }  
        }
        return count;
    }
};