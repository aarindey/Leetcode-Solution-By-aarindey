
class Solution {
public:
   string removeDuplicates(string S,int k) {
   stack<pair<char,int> > s;
for(int i=0;i<S.length();i++)
{
    if(s.empty()||s.top().first!=S[i])
    {
        pair p(S[i],1);
        s.push(p);
    }
    else if(s.top().first==S[i])
    {
        s.top().second++;
        if(s.top().second==k)
         s.pop();   
    }
}
        string ans="";
        int count=0;
        while(!s.empty())
        {
            count=s.top().second;
            while(count--)
            {
            ans.push_back(s.top().first);
            }
               s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
}    
};