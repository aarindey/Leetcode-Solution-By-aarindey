class Solution {
public:
    char least(vector<int>& count)
    {
        for(int i=0;i<26;i++)
        {
            if(count[i]!=0)
            {
                return ('a'+i);
            }
        }
        return 'z';
    }
    string robotWithString(string s) {
        int n=s.length();
        string ans="";
        stack<char> st;
        vector<int> count(26,0);
        for(char &ch:s)
        {
            count[ch-'a']++;
        }
        for(int i=0;i<n;i++)
        {
            st.push(s[i]);
            count[s[i]-'a']--;
            while(st.size()>0&&least(count)>=st.top())
            {
                ans+=st.top();
                st.pop();
            }
        }
        return ans;
    }
};