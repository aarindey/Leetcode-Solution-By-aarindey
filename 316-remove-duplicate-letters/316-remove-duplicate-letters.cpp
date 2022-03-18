class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.length();
        vector<int> freq(256,0);
        vector<bool> vis(256,false);
        string ans="";
        stack<char> st;
        for(char ch:s)
        {
            freq[ch]++;
        }
        for(char ch:s)
        {
            if(!vis[ch])
            {
                if(st.empty())
                {
                    st.push(ch);
                    vis[ch]=true;
                    freq[ch]--;
                }else
                {
                    if(st.top()<ch)
                    {
                     st.push(ch);
                     vis[ch]=true;
                     freq[ch]--;
                    }
                    else if(freq[st.top()]>0)
                    {
                        while(!st.empty()&&freq[st.top()]>0&&st.top()>ch)
                        {
                        vis[st.top()]=false;
                        st.pop();
                        }
                        st.push(ch);
                        vis[ch]=true;
                        freq[ch]--;
                    } 
                    else
                    {
                     st.push(ch);
                     vis[ch]=true;
                     freq[ch]--;
                    } 
                }
            }
            else
            {
                freq[ch]--;
            }
        }
        
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};