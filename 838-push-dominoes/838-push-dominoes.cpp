class Solution {
public:
    string pushDominoes(string d) {
        int n=d.size();
        int i=0;
        int j=0;
        string s(n,'.');
        if(d==s)
        return d;
        while(j<n)
        {
            if(d[j]=='.')
            {
                i=j;
                while(j<n&&d[j]=='.')
                {
                    j++;
                }
        
                if(i==0)
                {
                    if(d[j]=='L')
                    {
                        while(i<j)
                        {
                            d[i]='L';
                            i++;
                        }
                    }
                }
                else if(j==n)
                {
                    if(d[i-1]=='R')
                    {
                        while(i<j)
                        {
                            d[i]='R';
                            i++;
                        }
                    }
                }
                else
                {
                    if(d[j]=='L'&&d[i-1]=='R')
                    {
                        int len=j-(i-1)+1;
                        if(len%2==0)
                        {
                            int z=len/2;
                            int k=z;
                            --i;
                            while(z--)
                            {
                                d[i++]='R';
                            }
                            while(k--)
                            {
                                d[j--]='L';
                            }
                        }
                        else
                        {
                            int z=len/2;
                            int k=z;
                            --i;
                            while(z--)
                            {
                                d[i++]='R';
                            }
                            while(k--)
                            {
                                d[j--]='L';
                            } 
                        }
                    }
                    if(d[j]=='L')
                    {
                        while(i<j)
                        {
                            d[i]='L';
                            i++;
                        }
                    }
                    if(d[i-1]=='R')
                    {
                        while(i<j)
                        {
                            d[i]='R';
                            i++;
                        }
                    }
                }
            }

            j++;
        }
        return d;
    }
};