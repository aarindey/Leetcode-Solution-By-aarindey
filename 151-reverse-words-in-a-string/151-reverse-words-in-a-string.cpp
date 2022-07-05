
class Solution {
public:
    string reverseWords(string s) {   
        s=' '+s;
        string sub;
        string ans="";
        int right=s.length()-1;
        int i=s.length()-1;
         while(s[i]==' ')
         {
             i--;  
             right--;   
         }
        while(i>=0)
        {   
            sub="";
            if(s[i]==' ')
            {
                sub=s.substr(i+1,right-i);
                ans+=sub;
                if(i!=0)
                ans+=' ';
                if(i!=0)
                right=i-1;
            }
            i--;
        }   
        
        if(ans[ans.length()-1]==' ')
            ans.pop_back();
         if(ans[ans.length()-1]==' ')
            ans.pop_back();
         if(ans[ans.length()-1]==' ')
            ans.pop_back();
          if(ans[0]==' ')
          ans=ans.substr(1,ans.length()-1);
          ans+=' ';
        ans+='x';
        vector<string> z;
        int left=0;
        for(int i=0;i<ans.size();i++)
        {
            if(i+1<ans.size()&&ans[i]==' '&&ans[i+1]!=' ')
            {
                z.push_back(ans.substr(left,i-left+1));
                left=i+1;
            }
        }
        
        for(int i=0;i<z.size();i++)
        {
            while(isspace(*z[i].rbegin()))
            {
                z[i].pop_back();
            }
        }
        string res="";
        for(int i=0;i<z.size();i++)
        {
            res+=z[i];
            res+=' ';
        }
        res.pop_back();
        return res;
    }
};