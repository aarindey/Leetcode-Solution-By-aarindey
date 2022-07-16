class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
       int n=temp.size();
       vector<int> ans(n);
       stack<int> s;
       for(int i=n-1;i>=0;i--)
       {
           while(!s.empty())
           {
           if(temp[s.top()]>temp[i])
           {
               ans[i]=s.top()-i;
               s.push(i);
               break;
           }
           else
           {
               s.pop();
           }
           }
           if(s.empty())
           {
               ans[i]=0;
               s.push(i);
           } 
       }
       return ans;
    }
};