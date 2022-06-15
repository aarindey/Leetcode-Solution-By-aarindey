class Solution {
public:
    bool static comp(vector<int> &a,vector<int> &b)
    {
        if(a[1]==b[1])
        {
            return a[0]<b[0];
        }
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),comp);
        int prev=0;
        int n=courses.size();
        int ans=0;
        priority_queue<int> dur;
        for(int i=0;i<n;i++)
        {
            if(prev+courses[i][0]<=courses[i][1])
            {
                ans++;
                dur.push(courses[i][0]);
                prev+=courses[i][0];
            }
            else if(dur.size()>0&&courses[i][0]<dur.top())
            {
                int ele=dur.top();
                prev-=ele;
                dur.pop();
                dur.push(courses[i][0]);
                prev+=courses[i][0];
            }  
        }
        return dur.size();
    }
};