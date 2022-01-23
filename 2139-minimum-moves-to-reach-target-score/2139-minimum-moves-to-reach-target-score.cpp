class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int res=0;
        while(target&&maxDoubles)
        {
            if(target%2==1)
            {
                target--;
            }
            else
            {
                maxDoubles--;
                target/=2;
            }
            res++;
        }
        int ans=res+target-1;
        return ans;
    }
};