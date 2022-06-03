class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ans=0;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            int xorr=0;
            for(int j=i;j<n;j++)
            {
                xorr^=arr[j];
                if(xorr==0)
                ans+=j-i;
            }
        }
        return ans;
    }
};