class Solution {
public:
    int minMutation(string beginWord, string endWord, vector<string>& bank) {
        set<string> st;
        for(string &x:bank)
        {
            st.insert(x);
        }
        if(st.find(endWord)==st.end())
        return -1;
        set<string> store;
        store.insert(beginWord);
        int n=beginWord.size();
        queue<string> q;
        q.push(beginWord);
        int level=0;
        vector<char> v={'A','T','G','C'};
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
                    for(int j=0;j<4;j++)
                    {
                        char ch=v[j];
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
        return -1; 
    }
};