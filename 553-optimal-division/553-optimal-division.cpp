class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        return to_string(nums[0]);
        if(n==2)
        {
            string s=to_string(nums[0])+'/'+to_string(nums[1]);
            return s;
        }
        string ans="";
        for(int i=0;i<n;i++)
        {
            ans+=to_string(nums[i]);
            ans+='/';
            if(i==0)
            {
                ans+='(';
            }
        }
        ans.pop_back();
        ans+=')';
        return ans;
    }
};