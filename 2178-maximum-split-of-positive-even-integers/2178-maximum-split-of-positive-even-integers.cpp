class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> ans;
        if(finalSum%2!=0)
        return ans;
        long long i=2;
        while(i<=finalSum)
        {
            ans.push_back(i);
            finalSum-=i;
            i+=2;
        }
        int n=ans.size();
        ans[n-1]+=finalSum;
        return ans;
    }
};