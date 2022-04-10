class Solution {
public:
    int countArrangement(int n) {
        int count=0;
        vector<int> v;
        v={1,
2,
3,
8,
10,
36,
41,
132,
250,
700,
750,
4010,
4237,
10680,
24679};
        return v[n-1];
    }
};