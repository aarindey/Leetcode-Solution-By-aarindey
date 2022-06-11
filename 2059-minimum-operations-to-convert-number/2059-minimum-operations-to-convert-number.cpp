class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int n=nums.size();
        queue<int> q;
        set<int> st;
        q.push(start);
        int level=0;
        while(!q.empty())
        {
            int size=q.size();
            level++;
            for(int i=0;i<size;i++)
            {
                int ele=q.front();
                q.pop();
                if(ele<0||ele>1000)
                {
                    continue;
                }
                if(st.find(ele)!=st.end())
                {
                    continue;
                }
                st.insert(ele);
                for(int i=0;i<n;i++)
                {
                    if(ele+nums[i]==goal)
                    {
                        return level;
                    }
                    if(ele-nums[i]==goal)
                    {
                        return level;   
                    }
                    if((ele^nums[i])==goal)
                    {
                        return level;
                    }
                    
                    q.push(ele+nums[i]);
                    q.push(ele-nums[i]);
                    q.push(ele^nums[i]);
                }
            }
        }
        return -1;
    }
};