class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long temp=0;
        long long new_upper=0,new_lower=0;
        int n=differences.size();
        for(int i=0;i<n;i++)
        {
            temp+=differences[i];
            new_upper=max(new_upper,temp);
            new_lower=min(new_lower,temp);
        }
        return (int)max((long long)0,(upper-lower)-(new_upper-new_lower)+1);
    }
};