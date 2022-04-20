class Solution {
public:
    bool static comp(string &a,string &b)
    {
        return (a+b)>(b+a);
    }
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for(auto num:nums)
        {
            v.push_back(to_string(num));
        }
        sort(v.begin(),v.end(),comp);
        string ans="";
        for(auto s:v)
        {
            ans+=s;
        }
        while(ans[0]=='0'&&ans.length()>1)
        {
            ans.erase(0,1);
        }
        return ans;
    }
};