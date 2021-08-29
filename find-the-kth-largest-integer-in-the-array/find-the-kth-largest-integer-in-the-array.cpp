class Solution {
public:
    bool static comp(string &a,string &b)
    {
        int i=0;
        if(a.size()==b.size())
        {
        while(i!=a.size()-1&&a[i]==b[i])
        {
            i++;
        }  
         return a[i]<b[i];
        }
        return a.size()<b.size();
    }    
    string kthLargestNumber(vector<string>& nums, int k) {
    int n=nums.size();
    sort(nums.begin(),nums.end(),comp);
     return nums[n-k];   
    }
};