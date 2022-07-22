class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        ans.push_back(1);
        for(int i=1;i<n;i++)
        {
            int sz=ans.size();
            int add=pow(2,i);
            for(int j=sz-1;j>=0;j--){
                ans.push_back(ans[j]+add);
            }
        }
        return ans;
    }
};