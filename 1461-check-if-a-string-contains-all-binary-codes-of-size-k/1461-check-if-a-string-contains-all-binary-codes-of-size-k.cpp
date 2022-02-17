class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        string sub=s.substr(0,k);
        st.insert(sub);
        int n=s.length();
        for(int i=k;i<n;i++)
        {
            sub=sub.substr(1)+s[i];
            st.insert(sub);
        }
        return st.size()==pow(2,k);
    }
};