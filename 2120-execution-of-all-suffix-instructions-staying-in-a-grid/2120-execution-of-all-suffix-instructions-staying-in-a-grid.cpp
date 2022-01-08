class Solution {
public:
    vector<int> ans;
    int sum=0;

    void helper(int n,int j,int k,string s,int n1,int i)
    {
      if(j>=n||k>=n||j<0||k<0||i==n1)
      {
          ans.push_back(sum);
          return;
      }
        bool enter=false;
        if(s[i]=='U'&&j!=0)
        {
            sum++;
            j--;
            enter=true;
            i++;
        }if(s[i]=='D'&&j!=n-1)
        {
            sum++;
            j++;
            enter=true;
            i++;
        }if(s[i]=='L'&&k!=0)
        {
            sum++;
            k--;
            enter=true;
            i++;
        }
        if(s[i]=='R'&&k!=n-1)
        {
            sum++;
            k++;
            enter=true;
            i++;
        }
        if(enter==false)
        {
            ans.push_back(sum);
            return;
        }
        helper(n,j,k,s,n1,i);
        
    }
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int n1=s.size();
        if(n1==0)
        return ans;
        
        for(int i=0;i<n1;i++)
        {
            sum=0;
            int j=startPos[0];
            int k=startPos[1];
            if(j>=n||k>=n||j<0||k<0)
      {
          ans.push_back(0);
      }
            else
            helper(n,startPos[0],startPos[1],s,n1,i);
        }
        
        return ans;
    }
};