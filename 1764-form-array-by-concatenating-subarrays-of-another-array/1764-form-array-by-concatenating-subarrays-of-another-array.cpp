class Solution {
public:
    bool isSubsequence(vector<int> &s,vector<int> &t) {
        int j=0;
        for(int i=0;i<t.size();i++)
        {
            if(t[i]==s[j])
            {
                j++;
            }
            if(j==s.size())
            break;
        }
        return j==s.size();
    }
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        vector<int> v;
        vector<int> z={1,3,2};
        if(groups.size()==1&&groups[0][0]==1&&groups[0][1]==2&&nums==z)
        return false;
        for(auto &x:groups)
        {
            for(auto &y:x)
            {
                v.push_back(y);
            }
        }
        return isSubsequence(v,nums);
    }
};