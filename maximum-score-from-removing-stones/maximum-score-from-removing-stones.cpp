class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> q;
        q.push(a);
        q.push(b);
        q.push(c);
        int count=0;
        while(true)
        {
            int f=q.top();
            q.pop();
            int s=q.top();
            q.pop();
            if(f==0||s==0)
            break;
            f--;
            s--;
            count++;
            q.push(f);
            q.push(s);
        }
        return count;
    }
};