class Solution {
public:
    string removeDuplicates(string S) {
   stack<char> s;
for(int i=0;i<S.length();i++)
{
    if(s.empty()||s.top()!=S[i])
    {
        s.push(S[i]);
    }
    else if(s.top()==S[i])
    {
        s.pop();
    }
}
        string ans="";
        while(!s.empty())
        {
            ans+=s.top();
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
}    
};