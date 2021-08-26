class Solution {
public:
    bool isValidSerialization(string preorder) {
        preorder+=',';
        int n=1,len=preorder.length(),left=0;
    string sub="";
        if(len-1!=1&&preorder[0]=='#')
        return false;
     for(int i=0;i<len;i++)
     {
      if(preorder[i]==',')
      {
  sub=preorder.substr(left,i-left);
  if(sub=="#")
   n--;
   else
    n++;
    left=i+1;
          if(i<len-2&&n<=0)
           return false;
      }     
     }
     return n==0;   
    }
};