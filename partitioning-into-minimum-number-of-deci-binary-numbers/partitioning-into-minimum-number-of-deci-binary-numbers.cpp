class Solution {
public:
    int minPartitions(string n) {
        int m=INT_MIN;
        for(char c:n)
        {
            m=max(c-'0',m);
        }
        return m;
    }
};