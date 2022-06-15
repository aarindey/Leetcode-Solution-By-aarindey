class Solution {
public:
    static bool comp(string &a,string &b)
    {
        return a.size()<b.size();
    }
    bool check(string &s1,string &s2)
    {
        if(!(s2.size()==s1.size()+1))
        {
            return false;
        }
        int n=s2.size();
        for(int i=0;i<n;i++)
        {
            string s=s2;
            s.erase(i,1);
            if(s1==s)
            {
                return true;
            }
        }
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<int> lis(n,1);
        sort(words.begin(),words.end(),comp);
        int maxi=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(check(words[j],words[i])&&(lis[j]+1)>lis[i])
                {
                    lis[i]=lis[j]+1;
                    maxi=max(lis[i],maxi);
                }
            }
        }
        return maxi;
    }
};