class Solution{
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int l=searchWord.length();
        sentence+=' ';
        int j=0;
        string str;
        int c=0;
        for(int i=0;i<sentence.length();i++)
        {
            if(sentence[i]==' ')
            {
                 c++; 
                 str=sentence.substr(j,i-j);
                 if(str.length()>=l)
                 {
                    if(str.find(searchWord)==0)
                    return c;
                 }
                 j=i+1;
                if(i==sentence.length()-1)
                 break;   
                }
             }
            return -1;
        }
};