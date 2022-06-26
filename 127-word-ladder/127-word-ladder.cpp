class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st;
        for(string &x:wordList)
        {
            st.insert(x);
        }
        if(st.find(endWord)==st.end())
        return 0;
        set<string> store;
        store.insert(beginWord);
        int n=beginWord.size();
        queue<string> q;
        q.push(beginWord);
        int level=1;
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                string x=q.front();
                q.pop();
                for(int i=0;i<n;i++)
                {
                    string temp=x;
                    for(int j=0;j<26;j++)
                    {
                        char ch='a'+j;
                        if(temp[i]==ch)
                        continue;
                        temp[i]=ch;
                        if(store.find(temp)!=store.end())
                        {
                            continue;
                        }
                        if(st.find(temp)==st.end())
                        {
                            continue;
                        }
                        if(temp==endWord)
                        {
                            return level+1;
                        }
                        else
                        {
                            q.push(temp);
                            store.insert(temp);
                        }
                    }
                }
            }
            level++;
        }
        return 0;
    }
};