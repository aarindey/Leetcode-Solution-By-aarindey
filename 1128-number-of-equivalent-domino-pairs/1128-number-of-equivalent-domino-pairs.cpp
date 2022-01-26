class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& d) {
        int n=d.size();
        map<vector<int>,int> freq;
        for(int i=0;i<n;i++)
        {
            vector<int> ele=d[i];
            if(ele[0]<ele[1])
            {
                swap(ele[0],ele[1]);
            }
            freq[ele]++;
        }
        int ans=0;
        for(auto pr:freq)
        {
            if(pr.second>1)
            {
                int x=pr.second;
                ans+=(x*(x-1)/2);
            }
        }
        return ans;
    }
};