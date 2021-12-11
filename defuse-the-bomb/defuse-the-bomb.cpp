class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans;
        int n=code.size();
        for(int i=0;i<n;i++)
        {
            int j=1,sum=0;
            int m=i;
            if(k<0)
            {
            m+=n;
            int j=-1;
            while(j>=k)
            {
                sum+=code[(m+j)%n];
                j--;
            }
            }
            else
            {
            while(j<=k)
            {
                sum+=code[(m+j)%n];
                j++;
            }
            }
            ans.push_back(sum);
        }
        return ans;
    }
};