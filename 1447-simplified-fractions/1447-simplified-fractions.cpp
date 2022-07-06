class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> v;
        set<double> st;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(i==j)
                {
                    continue;
                }
                double frac=(double)(1.0*i/j);
                if(st.find(frac)==st.end())
                {
                    v.push_back(to_string(i)+'/'+to_string(j));
                    st.insert(frac);
                }
            }
        }
        return v;
    }
};