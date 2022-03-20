class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
     int n=ast.size();
        stack<int> s;
        s.push(ast[0]);
        for(int i=1;i<n;i++)
        {
         if(!s.empty()&&ast[i]*s.top()<0&&ast[i]<0)
         {
             if(abs(ast[i])==abs(s.top()))
                s.pop();
             else if(abs(ast[i])>abs(s.top()))
             {
                 while(!s.empty()&&s.top()*ast[i]<0&&abs(ast[i])>abs(s.top()))
                 {
                     s.pop();
                 }
                 bool ff=false;
                 if(!s.empty()&&s.top()*ast[i]<0&&ast[i]<0&&abs(ast[i])<=abs(s.top()))
                 {
                     ff=true;
                     if(abs(ast[i])==abs(s.top()))
                     s.pop();
                 }
                 
                 if(!ff)
                 s.push(ast[i]);
             }
            
           }
           else
           {
               s.push(ast[i]);
           }
        }
        vector<int> ans;
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};