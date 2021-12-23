class Solution {
public:
    int lengthoflis(vector<int> &arr)
    {
       vector<int> sub;
        for (int i = 0; i < arr.size(); ++i) {
            int x = arr[i];
            if (sub.empty() || sub[sub.size() - 1] <= x) { // Append to LIS if new element is >= last element in LIS
                sub.push_back(x);
            } else {
                int idx = upper_bound(sub.begin(), sub.end(), x) - sub.begin(); // Find the index of the smallest number > x
                sub[idx] = x; // Replace that number with x
            }
        }
        return sub.size();
    }
    int kIncreasing(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> temp;
        int ans=0;
        for(int i=0;i<k;i++)
        {
            temp.clear();
            for(int j=i;j<n;j+=k)
            {
                temp.push_back(arr[j]);
            }
            ans+=(temp.size()-lengthoflis(temp));
        }
        return ans;
    }
};
