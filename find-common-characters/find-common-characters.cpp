class Solution {
public:
    vector<string> commonChars(vector<string> A){
       vector<int> main(26,0);
       vector<int> temp(26,0);
       for(int i=0;i<A[0].length();i++)
       {
           main[A[0][i]-'a']++;
       }
       for(int i=1;i<A.size();i++)
       {
           for(int j=0;j<A[i].length();j++)
           {
               temp[A[i][j]-'a']++;
           }
           for(int j=0;j<26;j++)
           {
               main[j]=min(main[j],temp[j]);
               temp[j]=0;
           }
       }
        vector<string> ans;
       for(int i=0;i<26;i++)
       {
           if(main[i]>0)
           {
               while(main[i]--)
               {
                   string str="";
                   str.append(1,(char)(i+97));
                   ans.push_back(str);
               }
           }
       }
        return ans;
    }
};