class Solution {
public:
    bool isvowel(char ch) {
        ch=tolower(ch);
        return (ch == 'a') || (ch == 'e') ||(ch == 'i') ||(ch == 'o') ||(ch == 'u'); }
    string reverseVowels(string s) 
    {
       vector<char> vowels;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(isvowel(s[i]))
             vowels.push_back(s[i]);   
        }
        string ans="";
        int j=0;
        for(int i=0;i<s.length();i++)
        {
            if(isvowel(s[i]))
            {
                s[i]=vowels[j];
                j++;
            }  
        }   
       return s; 
    }
};