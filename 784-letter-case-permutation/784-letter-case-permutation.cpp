class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        queue<string> q;
        q.push(s);
        int n=s.length();
        vector<string> ans;
        for(int i=n-1;i>=0;i--)
        {
            if(isalpha(s[i]))
            {
                int len=q.size();
                while(len--)
                {
                    string element=q.front();
                    q.pop();
                    string left,right,res1="",res2="";
                    left=element.substr(0,i);
                    right=element.substr(i+1);
                    if(s[i]>=65&&s[i]<=90)
                    {
                        res1=left+element[i]+right;
                        res2=left+(char)(element[i]+32)+right;
                    }
                    else
                    {
                        res1=left+element[i]+right;
                        res2=left+(char)(element[i]-32)+right;                 
                    }
                    q.push(res1);
                    q.push(res2);
                }
            }
        }
        while(q.size()>0)
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};