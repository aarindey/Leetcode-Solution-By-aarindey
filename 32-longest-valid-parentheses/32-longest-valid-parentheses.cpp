class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> temp1;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                temp1.push_back(-1);
            }
            else 
            {
                temp1.push_back(-2);
            }
        }
        bool ok=true;
        while(ok)
        {
            ok=false;
            vector<int> temp2;
            n=temp1.size();
            for(int i=0;i<n;i++)
            {
                if(i+1<n&&temp1[i]==-1&&temp1[i+1]==-2)
                {
                    temp2.push_back(2);
                    i++;
                    ok=true;
                }
                else if(i+1<n&&temp1[i]>0&&temp1[i+1]>0)
                {
                    temp2.push_back(temp1[i]+temp1[i+1]);
                    i++;
                    ok=true;
                }
                else if(i+2<n&&temp1[i]==-1&&temp1[i+2]==-2&&temp1[i+1]>0)
                {
                    temp2.push_back(temp1[i+1]+2);
                    i+=2;
                    ok=true;
                }
                else
                {
                    temp2.push_back(temp1[i]);
                }
            }
            temp1=temp2;
        }
        int ans=INT_MIN;
        n=temp1.size();
        for(int i=0;i<n;i++)
        {
            ans=max(ans,temp1[i]);
        }
        if(ans<0)
        return 0;
        return ans;
    }
};