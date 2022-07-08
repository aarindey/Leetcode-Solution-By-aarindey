class Solution {
public:
    int reachNumber(int target) {
        int sum=0;
        int steps=0;
        target=abs(target);
        while(sum<target)
        {
            sum+=steps;
            steps++;
        }
        while(abs(target-sum)%2!=0)
        {
            sum+=steps;
            steps++;
        }
        return steps-1;
    }
}; 