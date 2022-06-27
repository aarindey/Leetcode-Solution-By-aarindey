class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        if(n<10)
        return n;
        string z=to_string(n);
        int idx;
        int m=z.size();
        for(int i=0;i<m;i++)
        {
            if(i==m-1)
            {
                return n;
            }
        
            if(z[i+1]<z[i])
            {
                idx=i;   
                break;
            }
        }
        while(idx-1>=0&&z[idx-1]==z[idx])
        {
            idx--;
        }
        z[idx]=(z[idx]-'1')+'0';
        for(int i=idx+1;i<m;i++)
        {
            z[i]='9';
        }
        return stoi(z);
    }
};