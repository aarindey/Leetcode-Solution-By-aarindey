class Solution {
public:
    int minInsertions(string s) {
        int x=0,n=s.length();
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                v.push_back(1);
            }
            else if(i<n-1&&s[i]==')'&&s[i+1]==')')
            {
                v.push_back(2);
                i++;
            }
            else
            {
                v.push_back(2);
                x++;
            }
        }
        stack<int> st;
        n=v.size();
        for(int i=0;i<n;i++)
        {
            if(!st.empty()&&st.top()==1&&v[i]==2)
            {
                st.pop();
            }
            else
            {
                st.push(v[i]);
            }
        }
        int count=0;
        n=st.size();
        while(!st.empty())
        {
            if(st.top()==1)
            count++;
            st.pop();
        }
        return x+2*count+(n-count);
    }
};