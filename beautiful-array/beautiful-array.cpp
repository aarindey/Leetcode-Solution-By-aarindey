class Solution {
public:
    vector<int> beautifulArray(int n) {
       vector<int> ans;
        ans.push_back(1);
        vector<int> temp;
        while(ans.size()<n)
        {
            temp.clear();
            for(auto i:ans)
            {
                if(2*i-1<=n)
                {
                    temp.push_back(2*i-1);
                }
            }
            for(auto i:ans)
            {
                if(2*i<=n)
                {
                    temp.push_back(2*i);
                }
            }
            ans=temp;
        }
        return ans;
    }
};