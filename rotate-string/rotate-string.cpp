class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.length(),n2=goal.size();
        if(n!=n2)
        return false;
        s+=s;
        for(int i=0;i<2*n;i++)
        {
            if(s.substr(i,n)==goal)
            return true;
        }
        return false;
    }
};