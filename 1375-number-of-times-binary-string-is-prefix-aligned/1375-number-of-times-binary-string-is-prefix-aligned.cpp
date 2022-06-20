class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int c=0;
        int last_one=0;
        int n=flips.size();
        for(int i=0;i<n;i++)
        {
            last_one=max(last_one,flips[i]);
            if(last_one!=0&&last_one==i+1)
            {
                cout<<i<<endl;
                c++;
            }
        }
        return c;
    }
};