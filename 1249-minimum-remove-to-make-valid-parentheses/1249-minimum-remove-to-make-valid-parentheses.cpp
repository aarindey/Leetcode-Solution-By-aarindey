class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>> st;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push({'(',i});
            }
            else if(s[i]==')')
            {
                if(!st.empty()&&st.top().first=='(')
                {
                    st.pop();
                }
                else
                {
                    st.push({')',i});
                }
            }
        }
        while(!st.empty())
        {
            int idx=st.top().second;
            st.pop();
            s[idx]='#';
        }
        string ans="";
        for(int i=0;i<n;i++)
        {
            if(s[i]!='#')
            {
                ans+=s[i];
            }
        }
        return ans;
    }
};