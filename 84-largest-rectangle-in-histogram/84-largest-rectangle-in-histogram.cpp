class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> nextSmaller(n),prevSmaller(n);
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                prevSmaller[i]=-1;
                st.push(i);
            }
            else
            {
                prevSmaller[i]=st.top();
                st.push(i);
            }
        }
        stack<int> st2;
        for(int i=n-1;i>=0;i--)
        {
            while(!st2.empty()&&heights[st2.top()]>=heights[i])
            {
                st2.pop();
            }
            if(st2.empty())
            {
                nextSmaller[i]=n;
                st2.push(i);
            }
            else
            {
                nextSmaller[i]=st2.top();
                st2.push(i);
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,heights[i]*(nextSmaller[i]-prevSmaller[i]-1));
        }
        return ans;
    }
};