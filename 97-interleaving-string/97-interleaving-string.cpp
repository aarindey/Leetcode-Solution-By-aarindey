class Solution {
public:
    unordered_map<string,bool> memo;
    bool fun(string &s1,string &s2,string &s3,int p1,int p2,int p3,int l1,int l2,int l3)
    {
        //Base condition
        if(p3==l3)
        {
            if(p1==l1&&p2==l2)
            {
                return true;
            }
            return false;
        }
        //Applying Memo using star separated pointers as key
        string key=to_string(p1)+"*"+to_string(p2)+"*"+to_string(p3);
        if(memo.find(key)!=memo.end())
        return memo[key];
        
        // When one of the pointers have reached the end
        if(p1==l1)
        {
            if(s2[p2]==s3[p3])
            {
                return memo[key]=fun(s1,s2,s3,p1,p2+1,p3+1,l1,l2,l3);
            }
            else
            {
                return memo[key]=false;
            }
        }
        if(p2==l2)
        {
            if(s1[p1]==s3[p3])
            {
                return memo[key]=fun(s1,s2,s3,p1+1,p2,p3+1,l1,l2,l3);
            }
            else
            {
                return memo[key]=false;
            }
        }

        // Otherwise
        bool ans=false;
        if(s1[p1]==s3[p3])
        {
            ans|=fun(s1,s2,s3,p1+1,p2,p3+1,l1,l2,l3);
        }
        if(s2[p2]==s3[p3])
        {
            ans|=fun(s1,s2,s3,p1,p2+1,p3+1,l1,l2,l3);
        }
        return memo[key]=ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int l1,l2,l3,p1,p2,p3;
        p1=p2=p3=0;
        l1=s1.size();
        l2=s2.size();
        l3=s3.size();
        if(l3!=l1+l2)
        {
            return false;
        }
        return fun(s1,s2,s3,p1,p2,p3,l1,l2,l3);
    }
};