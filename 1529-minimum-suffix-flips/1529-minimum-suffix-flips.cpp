class Solution {
public:
    int minFlips(string target) {
        int ans=0;
        int n=target.size();
        bool one=false;
        for(int i=0;i<n;i++)
        {
            if(target[i]=='0'&&!one)
            continue;
            else if(target[i]=='0'&&one)
            {
                ans++;
                one=false;
            }
            else if(target[i]=='1'&&!one)
            {
                ans++;
                one=true;
            }
        }
        return ans;
    }
};