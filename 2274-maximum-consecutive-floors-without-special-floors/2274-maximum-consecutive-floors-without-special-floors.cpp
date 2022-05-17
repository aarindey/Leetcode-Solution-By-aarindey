class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        special.push_back(top+1);
        special.push_back(bottom-1);
        sort(special.begin(),special.end());
        int ans=INT_MIN;
        for(int i=1;i<special.size();i++)
        {
            ans=max(special[i]-special[i-1]-1,ans);
        }
        return ans;
    }
};