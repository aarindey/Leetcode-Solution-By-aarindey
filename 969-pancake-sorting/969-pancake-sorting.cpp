class Solution {
public:
    void modify(vector<int> &arr,int j,int i)
    {
        reverse(arr.begin(),arr.begin()+j+1);
        reverse(arr.begin(),arr.end()-i);
    }
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        vector<int> sorted;
        sorted=arr;
        int n=arr.size();
        sort(sorted.begin(),sorted.end());
        for(int i=0;i<n;i++)
        {
            int j=max_element(arr.begin(),arr.end()-i)-arr.begin();
            if(j+1!=n-i)
            {
            ans.push_back(j+1);
            ans.push_back(n-i);
            modify(arr,j,i);
            }
        }
        return ans;
    }
};