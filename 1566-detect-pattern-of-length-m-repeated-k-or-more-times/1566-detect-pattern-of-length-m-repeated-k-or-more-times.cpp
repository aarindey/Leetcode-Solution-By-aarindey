class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int n=arr.size(),curr=0;
        for(int i=0;(i+m)<n;i++)
        {
            if(arr[i]!=arr[i+m])
                curr=0;
            else if(arr[i]==arr[i+m])
            {
                curr++;    
            }
            if(curr==(k-1)*m)
            return true;
        }
        return false;
    }
};