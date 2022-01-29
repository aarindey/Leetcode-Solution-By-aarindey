class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxi=INT_MIN,n=heights.size();
        vector<int> ps(n),ns(n);
        stack<int> s;
        for(int i=0;i<n;i++)
        {
          while(!s.empty()&&heights[s.top()]>=heights[i])
          {
          s.pop();
          }
          if(s.empty())
          ps[i]=-1;
          else
          ps[i]=s.top();
          s.push(i);
        }
        while(!s.empty())
        s.pop();
        for(int i=n-1;i>=0;i--)
        {
         while(!s.empty()&&heights[s.top()]>=heights[i])
         {
             s.pop();
         }
         if(s.empty())
         ns[i]=n;
         else
         ns[i]=s.top();
         s.push(i);
        }
       for(int i=0;i<n;i++)
       {
           maxi=max(maxi,(ns[i]-ps[i]-1)*heights[i]);
       }
        return maxi;
    }
};