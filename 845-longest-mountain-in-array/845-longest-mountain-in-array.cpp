class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        for(int i=1;i<n-1;)
        {
            if(arr[i]>arr[i-1]&&arr[i]>arr[i+1])
            {
                int j=i;
                while(j>0&&arr[j-1]<arr[j])
                {
                    j--;
                }
                while(i<n-1&&arr[i+1]<arr[i])
                {
                    i++;
                }
                ans=max(ans,(i-j+1));
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};