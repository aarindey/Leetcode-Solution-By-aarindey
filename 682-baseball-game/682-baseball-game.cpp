#include<bits/stdc++.h>
class Solution {
public:
    int calPoints(vector<string> &ops)
    {
        stack<int> myStack;
        int score=0;
        for(int i=0;i<ops.size();i++)
        {
            if(ops[i]=="C")
                myStack.pop();
            else if(ops[i]=="D")
                myStack.push(2*myStack.top());
            else if(ops[i]=="+")
            {
                stack<int> temp;
                temp=myStack;
                int sum=0;
                for(int i=1;i<=2;i++)
                {
                  sum+=temp.top();
                    temp.pop();
                }
                myStack.push(sum);
            }
            else
            {
                int x=stoi(ops[i]);
                myStack.push(x);
            }
         }
         int sum=0;
         while(!myStack.empty())
         {
               sum+=myStack.top();
               myStack.pop();
         }
        return sum;
    }
};