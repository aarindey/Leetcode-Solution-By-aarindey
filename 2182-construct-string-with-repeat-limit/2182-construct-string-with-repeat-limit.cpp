class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
      vector<int> freq(26,0);
      int n=s.length();
        for(char ch:s)
        freq[ch-'a']++;
        int curr=0,k=0;
        string ans(n+n,'-');
        set<int> idx;
        for(int i=25;i>=0;i--)
        {
            curr=0;
            while(idx.size()&&freq[i]>0)
            {
                ans[*idx.begin()]='a'+i;
                freq[i]--;
                idx.erase(idx.begin());
            }
            if(idx.size()==0)
            while(freq[i]>0)
            {
                if(curr==repeatLimit)
                {
                    idx.insert(k);
                    k++;
                    curr=0;
                }
                ans[k]='a'+i;
                curr++;
                freq[i]--;
                k++;
            }
        }
        size_t found=ans.find('-');
        if(found!=string::npos)
        {
            return ans.substr(0,found);
        }
        return ans;
    }
};