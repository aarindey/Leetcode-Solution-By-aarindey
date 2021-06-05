class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        int count=0;
        int x=0;
        for(int i=1;i<=n;i++)
        {
            x=i;
            count=0;
            while(x)
            {
                if(x&1==1)
                 count++; 
                x=x>>1;
            }
            ans.push_back(count);
        }  
        return ans;
    }
};