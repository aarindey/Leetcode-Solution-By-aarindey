class Solution {
public:
    unordered_map<string,int> dp;
    string encode(vector<int> session,int i)
    {
        sort(session.begin(),session.end());
        string key="";
        for(auto s:session)
        {
            key+=to_string(s);
            key+="#";
        }
        key+=to_string(i);
        key+="#";
        return key;
    }
    int solve(vector<int> &tasks,vector<int> &session,int sessionTime,int i,int n)
    {
        if(i==n)
        {
            // for(int i=0;i<session.size();i++)
            // {
            //     cout<<session[i]<<" ";
            // }
            // cout<<endl;
            return 0;
        }
        string key=encode(session,i);
        if(dp.find(key)!=dp.end())
        {
            return dp[key];
        }
        int ans;
        //tasking a new task as a diiferent session
        session.push_back(tasks[i]);
        ans=1+solve(tasks,session,sessionTime,i+1,n);
        session.pop_back();
        // clubing new task in one of the old sessions which can accomodate it
        for(int j=0;j<session.size();j++)
        {
            if(session[j]+tasks[i]<=sessionTime)
            {
                session[j]+=tasks[i];
                ans=min(ans,solve(tasks,session,sessionTime,i+1,n));
                session[j]-=tasks[i];
            }
        }
        //the minimum of both the cases will give us our ans 
        return dp[key]=ans;
    }
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n=tasks.size();
        vector<int> session;
        return solve(tasks,session,sessionTime,0,n);
    }
};