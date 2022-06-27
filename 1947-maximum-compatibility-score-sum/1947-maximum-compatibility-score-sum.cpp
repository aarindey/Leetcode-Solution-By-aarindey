class Solution {
public:
    int findComp(vector<int> &m,vector<int> &s)
    {
        int n=m.size();
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(m[i]==s[i])
            c++;
        }
        // cout<<c<<endl;
        return c;
    }
    int maxCompatibilitySum(vector<vector<int>>& s, vector<vector<int>>& m) {
        
        int n=m.size();
        map<pair<int,int>,int> mp;
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<n;i++)
            {
                //{mentor,student}
                mp[{j,i}]=findComp(m[j],s[i]);
            }
        }
        string perm="";
        for(int i=0;i<n;i++)
        {
            perm+=('0'+i);
        }
        string x=perm;
        int ans=0;
        bool ok=true;
        while(ok||perm!=x)
        {
            ok=false;
            int cal=0;
            for(int i=0;i<n;i++)
            {
                cal+=mp[{i,perm[i]-'0'}];
            }
            // cout<<cal<<endl;
            ans=max(ans,cal);
            next_permutation(perm.begin(),perm.end());
        }
        return ans;
    }
};