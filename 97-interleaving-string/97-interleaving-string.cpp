class Solution {
public:
    unordered_map<string,bool> memo;
    bool helper(string s1,string s2,string s3,int n1,int n2,int n3,int i,int j,int k)
    {
        if(k==n3)
        {
            return (i==n1&&j==n2)?true:false;
        }
        string key=to_string(i)+"*"+to_string(j)+"*"+to_string(k);
        if(memo.find(key)!=memo.end())
        return memo[key];
        
        if(i==n1)
        {
            return memo[key]=(s2[j]==s3[k])?helper(s1,s2,s3,n1,n2,n3,i,j+1,k+1):false;
        }
        if(j==n2)
        {
            return memo[key]=(s1[i]==s3[k])?helper(s1,s2,s3,n1,n2,n3,i+1,j,k+1):false;
        }
        bool case1,case2;
        case1=case2=false;
        if(s1[i]==s3[k])
        {
            case1=helper(s1,s2,s3,n1,n2,n3,i+1,j,k+1);
        }
        if(s2[j]==s3[k])
        {
            case2=helper(s1,s2,s3,n1,n2,n3,i,j+1,k+1);
        }
        return memo[key]=case1||case2;
    }
    bool isInterleave(string s1, string s2, string s3) {
      int n1,n2,n3;
        n1=s1.size();
        n2=s2.size();
        n3=s3.size();
        if(n3!=(n1+n2))
        return false;
        
        return helper(s1,s2,s3,n1,n2,n3,0,0,0);
    }
};