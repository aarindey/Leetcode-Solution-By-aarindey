class Solution {
public:
    int minPartitions(string n) {
        int m=n[0]-'0';
        for(char c:n)
        {
            m=max(c-'0',m);
        }
        return m;
    }
};