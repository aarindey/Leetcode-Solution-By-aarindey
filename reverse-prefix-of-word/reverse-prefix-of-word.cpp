class Solution {
public:
    string reversePrefix(string word, char ch) {
       int index=0;
       for(int i=0;i<word.length();i++)
       {
           if(word[i]==ch)
           {
           index=i;
           break;
           }
       }
       string str=word.substr(0,index+1);
       reverse(str.begin(),str.end());
       str+=word.substr(index+1);
       return str; 
    }
};