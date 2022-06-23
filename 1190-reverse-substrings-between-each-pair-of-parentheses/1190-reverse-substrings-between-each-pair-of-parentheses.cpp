class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else if(s[i]==')')
            {
                int low=st.top();
                st.pop();
                int high=i;
                reverse(s.begin()+low+1,s.begin()+high);
            }
        }
        string ans="";
        for(char &c:s)
        {
            if(c!='('&&c!=')')
            {
                ans+=c;
            }
        }
        return ans;
    }
};