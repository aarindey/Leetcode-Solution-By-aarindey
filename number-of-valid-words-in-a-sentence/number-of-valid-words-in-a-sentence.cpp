class Solution {
public:
    bool check(string s)
    {
        int low=0,pun=0,hyphen=0,dig=0;
        for(char c:s)
        {
            if(c>=97&&c<=122)
            low++;
            if(c=='!'||c=='.'||c==',')
            pun++;
            if(c=='-')
            hyphen++;
            if(isdigit(c))
            dig++;
        }
        if(low==s.length())
        return true;
        if(hyphen>1||pun>1||dig>0)
        return false;
        if(hyphen==0&&pun==1&&(s[s.length()-1]=='!'||s[s.length()-1]=='.'||s[s.length()-1]==','))
        return true;
        else if(hyphen==1&&pun==0&&s[0]!='-'&&s[s.length()-1]!='-')
        return true;
        else if(hyphen==1&&pun==1&&(s[s.length()-1]=='!'||s[s.length()-1]=='.'||s[s.length()-1]==',')&&(s[0]!='-'&&s[s.length()-2]!='-'))
        return true;
        else
        return false;
    }
    int countValidWords(string sentence) {
        int i=0;
        int left=0;
        int count=0;
        sentence+=' ';
        bool entered;
        while(sentence[i]==' ')
        i++;
        left=i;
        while(i<sentence.length())
        {
            entered=false;
            if(sentence[i]==' ')
            {
                entered=true;
                string s=sentence.substr(left,i-left);
                if(check(s))
                {
                    count++;
                }
                while(sentence[i]==' ')
                i++;
                left=i;
            }
            if(entered==false)
            i++;
        }
        return count;
    }
};