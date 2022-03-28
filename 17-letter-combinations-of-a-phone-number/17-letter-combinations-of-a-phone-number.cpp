class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> all={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(digits.empty())
        return {};
        vector<string> ans;
        ans.push_back("");
        for(char ch:digits)
        {
            int x=ch-'0';
            vector<string> temp;
            for(char ch2:all[x])
            {
                for(auto s:ans)
                {
                    temp.push_back(s+ch2);
                }
            }
            ans.swap(temp);
        }
        return ans;
    }
};