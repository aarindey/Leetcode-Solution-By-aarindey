class Solution {
public:
    bool isPathCrossing(string path) {
       pair<int,int> s;
    s.first=0;
    s.second=0;
        set<pair<int,int> > mp;
        mp.insert(s);
        for(int i=0;i<path.size();i++)
        {
            if(path[i]=='N')
            {
              s.second+=1;    
            }
            else if(path[i]=='E')
            {
                s.first+=1;
            }
            else if(path[i]=='S')
            {
                s.second-=1;
            }
            else if(path[i]=='W')
            {
                s.first-=1;
            }
            if(mp.find(s)!=mp.end())
            return true;
            mp.insert(s);
        }
        return false;
    }
};