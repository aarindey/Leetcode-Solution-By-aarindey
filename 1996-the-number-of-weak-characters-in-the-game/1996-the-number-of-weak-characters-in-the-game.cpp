class Solution {
public:
    bool static comp(vector<int> &a,vector<int> &b)
    {
        if(a[0]==b[0])
        {
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        sort(p.begin(),p.end(),comp);
        stack<int> st;
        int n=p.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                st.push(p[i][1]);
            }
            else
            {
                while(!st.empty()&&st.top()<p[i][1])
                {
                    st.pop();
                    ans++;
                }
                st.push(p[i][1]);
            }
        }
        return ans;
    }
};