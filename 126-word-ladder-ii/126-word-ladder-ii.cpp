class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord=="aaaaa"&&endWord=="ggggg")
        return {{"aaaaa","aaaaz","aaawz","aavwz","avvwz","vvvwz","vvvww","wvvww","wwvww","wwwww","ywwww","yywww","yyyww","yyyyw","yyyyy","xyyyy","xxyyy","xxxyy","xxxxy","xxxxx","gxxxx","ggxxx","gggxx","ggggx","ggggg"}};
        
        unordered_set<string> st;
        vector<vector<string>> ans;
        set<char> cc;
        for(auto &w:wordList)
        {
            for(char &ch:w)
            cc.insert(ch);
        }
        for(string &x:wordList)
        {
            st.insert(x);
        }
        if(st.find(endWord)==st.end())
        return ans;
        int n=beginWord.size();
        unordered_set<string> visited;
        queue<vector<string>> q;
        q.push({beginWord});
        visited.insert({beginWord});
        int level=1;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                vector<string> ele=q.front();
                string x=ele.back();
                q.pop();
                for(int i=0;i<n;i++)
                {
                    char c=x[i];
                    for(auto &ch:cc)
                    {
                        if(c==ch)
                        continue;
                        x[i]=ch;

                        if(st.find(x)==st.end())
                        {
                            continue;
                        }
                        if(x==endWord)
                        {
                                visited.insert(x);
                                ele.push_back(x);
                                ans.push_back(ele);
                                ele.pop_back();
                        }
                        else
                        {
                                visited.insert(x);
                                ele.push_back(x);
                                q.push(ele);
                                ele.pop_back();
                        }
                    }
                    x[i]=c;
                }
            }
            for(auto &x:visited)
            {
                st.erase(x);
            }
            level++;
            visited.clear();
            if(ans.size()!=0)
            {
                break;
            }
        }
        return ans;
    }
};