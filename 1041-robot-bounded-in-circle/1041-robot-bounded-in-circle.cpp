class Solution {
public:
    bool isRobotBounded(string ins) {
        char dir='N';
        int x=0,y=0;
        int n=ins.length();
        for(int i=0;i<n;i++)
        {
            if(ins[i]=='G')
            {
                if(dir=='N')
                {
                    y++;
                }
                else if(dir=='S')
                {
                    y--;
                }
                else if(dir=='E')
                {
                    x++;
                }
                else if(dir=='W')
                {
                    x--;
                }
            }
            else 
            {
                if(ins[i]=='L')
                {
                       if(dir=='N')
                {
                    dir='W';
                }
                else if(dir=='S')
                {
                    dir='E';
                }
                else if(dir=='E')
                {
                    dir='N';
                }
                else if(dir=='W')
                {
                    dir='S';
                }
                }
                else if(ins[i]=='R')
                {
                   
                       if(dir=='N')
                {
                    dir='E';
                }
                else if(dir=='S')
                {
                    dir='W';
                }
                else if(dir=='E')
                {
                    dir='S';
                }
                else if(dir=='W')
                {
                    dir='N';
                } 
                
            
        }
    }
    }
        if(dir!='N'||(x==0&&y==0))
        {
            return true;
        }
        return false;
    }
};