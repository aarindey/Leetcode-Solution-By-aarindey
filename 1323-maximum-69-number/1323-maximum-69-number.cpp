class Solution {
public:
    int maximum69Number (int num) {
        string s;
        s=to_string(num);
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='6')
            {
                s[i]='9';
                break;
            }
                
        }
        int a;
        a=stoi(s);
        return a; 
    }
};