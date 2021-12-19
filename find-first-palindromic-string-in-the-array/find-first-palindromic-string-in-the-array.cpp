class Solution {
public:
    bool palin(string w)
    {
        int i=0,j=w.size()-1;
        while(i<j)
        {
            if(w[i++]!=w[j--])
            {
                return false;
            }
            
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            if(palin(words[i]))
            return words[i];
        }
        return "";
    }
};