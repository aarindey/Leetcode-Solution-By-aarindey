class Solution {
public:
    int calculate(string s) {
        int n=s.length();
        stack<int> st;
        char sign='+';
        for(int i=0;i<n;i++)
        {
            if(isdigit(s[i]))
            {
                int val=0;
                while(isdigit(s[i]))
                {
                    val=val*10+(s[i]-'0');
                    i++;
                }
                i--;
                if(sign=='+')
                {
                    st.push(val);
                }
                else if(sign=='-')
                {
                    st.push(-val);
                }
                else if(sign=='*')
                {
                    int p=st.top();
                    st.pop();
                    p*=val;
                    st.push(p);
                }
                else if(sign=='/')
                {
                    int p=st.top();
                    st.pop();
                    p/=val;
                    st.push(p);
                }
            }
            else if(s[i]!=' ')
            {
                sign=s[i];
            }
        }
        int ans=0;
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};