class Solution {
public:
    int numDifferentIntegers(string word) {
       int count=0;
        string str;
        unordered_map<string,int> mp;
        for(int i=0;i<word.size();i++)
       {
           if(isdigit(word[i]))
           {
               int j=i;
               while(isdigit(word[j])&&j<word.size())
               {
                   j++;
               }
               str=word.substr(i,j-i);
               int z=0;
               while(str[z]=='0')    
               {
                   z++;
               }  
               if(str.substr(z).length()!=0)
               mp[str.substr(z)]++;
               else
               mp["0"]++;   
               i=j;
           }    
       } 
        return mp.size();
    }
};