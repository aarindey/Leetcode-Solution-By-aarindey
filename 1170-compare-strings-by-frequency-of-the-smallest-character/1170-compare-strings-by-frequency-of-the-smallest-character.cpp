class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> f;
        int n=words.size();
        for(auto word:words)
        {
            vector<int> v(26,0);
            int ans=0;
            int idx=INT_MAX;
            for(char &ch:word)
            {
                v[ch-'a']++;
                if(ch-'a'<=idx)
                {
                    idx=ch-'a';
                    ans=v[idx];
                }
            }
            cout<<ans<<endl;
            f.push_back(ans);
        }
        sort(f.begin(),f.end());
        vector<int> a;
        for(auto q:queries)
        {
            string word=q;
            vector<int> v(26,0);
            int ans=0;
            int idx=INT_MAX;
            for(char &ch:word)
            {
                v[ch-'a']++;
                if(ch-'a'<=idx)
                {
                    idx=ch-'a';
                    ans=v[idx];
                }
            }
            int i=upper_bound(f.begin(),f.end(),ans)-f.begin();
            if(i==n)
            {
            a.push_back(0);
            }
            else
            {
            a.push_back(n-i);
            }
        }
        return a;
    }
};