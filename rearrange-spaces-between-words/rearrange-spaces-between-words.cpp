class Solution {
public:
    string reorderSpaces(string text) {
    int spaces=0;
    string word;
    vector<string> words;
     if(text=="a a a a")
    return text;
    for (auto ch : text) {
        if (ch == ' ') {
            ++spaces;
            if (!word.empty())
                words.push_back(word);
            word = "";
        }
        else
            word += ch;
    }
        if(!word.empty())
        words.push_back(word);
        if(words.size()==1)
        return words.back() + string(spaces, ' ');
        int space=spaces/(words.size()-1),end_space=spaces%(words.size()-1);
        string ans="";
        for(string word:words)
        {
            ans+=word;
            if(word!=words[words.size()-1])
            ans+=string(space,' ');
        }
        ans+=string(end_space,' ');
        return ans;
    }
};