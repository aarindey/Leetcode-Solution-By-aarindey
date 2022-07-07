class Solution {
public:
    bool backtrack(string &s,int i,vector<int> &ans,int &n)
    {
        //Base Condtion
        if(i==n)
        {
            if(ans.size()>2)
            {
                return true;
            }
            return false;
        }

        int num=0;
        for(int j=i;j<n;j++)
        {
            if(num>=214748363)
            return false;
            num=num*10+(s[j]-'0');
            if(num<0)
            return false;
            long long last,lastlast;
            if(ans.size()>=2)
            {
                last=ans[ans.size()-1];
                lastlast=ans[ans.size()-2];
                if(last>1073741823&&lastlast>1073741823)
                return false;
            }
            if(ans.size()<2||last+lastlast==num)
            {
                ans.push_back(num);
                if(backtrack(s,j+1,ans,n))
                return true;
                ans.pop_back();
            }
            if(j==i&&s[j]=='0')
            return false;
        }
        return false;
    }
    vector<int> splitIntoFibonacci(string num) {
        vector<int> ans;
        int n=num.size();
        if(backtrack(num,0,ans,n))
        {
            return ans;
        }
        return {};
    }
};