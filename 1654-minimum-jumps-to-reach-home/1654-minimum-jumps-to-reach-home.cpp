class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        set<int> st,st2,st3;
        for(auto &x:forbidden)
        {
            st.insert(x);
        }
        queue<pair<int,int>> q;
        q.push({0,0});
        int level=0;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                pair<int,int> ele=q.front();
                q.pop();
                int pos,flag;
                pos=ele.first;
                flag=ele.second;
                if(pos==x)
                {
                    return level;
                }
                if(flag)
                {
                    if(st.find(pos+a)==st.end())
                    if(st3.find(pos+a)==st3.end()&&pos+a<=6000)
                    {
                        if(pos+a==x)
                        return level+1;
                        q.push({pos+a,0});
                        st3.insert(pos+a);
                    }
                }
                else
                {
                    if(st.find(pos+a)==st.end())
                    if(st3.find(pos+a)==st3.end()&&pos+a<=6000)
                    {
                        if(pos+a==x)
                        return level+1;
                        q.push({pos+a,0});
                        st3.insert(pos+a);
                    }
                    if(st.find(pos-b)==st.end())
                    if(pos-b>=0&&st2.find(pos-b)==st2.end())
                    {
                        if(pos-b==x)
                        return level+1;
                        q.push({pos-b,1});
                        st2.insert(pos-b);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};