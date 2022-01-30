class Solution {
public:
    bool isValid(string s) {
      stack<char> st;
        for(char &ch:s)
        {
          if(ch=='c')
          {
              if(st.size()<2)
              {
                  return false;
              }
              else
              {
                  char c1=st.top();
                  if(c1!='b')
                  {
                      return false;
                  }
                  st.pop();
                  char c2=st.top();
                  if(c2!='a')
                  {
                      return false;
                  }
                  st.pop();
              }
          }
          else
          {
              st.push(ch);
          }
        }
        return st.empty();
    }
};