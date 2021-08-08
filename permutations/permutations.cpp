class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int> a,int l,int r) {
         // Base case
    if (l == r)
     ans.push_back(a);   
    else
    {
        // Permutations made
        for (int i = l; i <= r; i++)
        {
 
            // Swapping done
            swap(a[l], a[i]);
 
            // Recursion called
            helper(a, l+1, r);
 
            //backtrack
            swap(a[l], a[i]);
        }
    } 
    }
    vector<vector<int>> permute(vector<int> &nums)
    {       
        helper(nums,0,nums.size()-1);
        return ans;
    }
};