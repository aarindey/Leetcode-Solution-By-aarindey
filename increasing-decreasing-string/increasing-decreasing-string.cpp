class Solution {
public:
    string sortString(string s) {
        map<char,int> mp;
// int alpha[26]={0};
//         string str="";
//         int n=s.length();
//         for(int i=0;i<n-1;i++)
//         {
//            int a=s[i]-97;
//             alpha[a]++;
//         }
//         while(n>0) 
//        {for(int i=0;i<26;i++)
//        {
//            if(alpha[i]>0)
//            {
//                alpha[i]--;
//                str+=char(i+97);
//                n--;
//            }
//        }
//           for(int i=25;i>=0;i--)
//           {
//               if(alpha[i]>0)
//               {
//               alpha[i]--;
//               str+=char(i+97);
//               n--;
//               }    
//           }
//         }
//         return str;
        int alpha[26];
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }  
        string str="";
        bool check=true;
        while(n>0)
        {
         for(auto pr:mp)
         {
             if(pr.second>0)
             {
              str+=pr.first;   
              mp[pr.first]--; 
                 n--;
             }
             }
             map<char,int>::reverse_iterator it;
             for(it=mp.rbegin();it!=mp.rend();it++)
             {
                 if(it->second>0)
                 {
                 str+=it->first;
                 mp[it->first]--;
                  n--;
                 }
             }  
         if(str.length()==s.length())
          break;   
    }
    return str;        
    }
};