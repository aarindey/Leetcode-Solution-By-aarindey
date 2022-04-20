class Solution {
public:
    bool valid(int mid,int m,vector<int> &pos)
    {
        int prev=0;
        int i,j;
        i=j=1;
        while(i<m)
        {
            while(j<pos.size()&&pos[prev]+mid>pos[j]) 
                j++;
            if(j>=pos.size())
            {
                return false;
            }
            prev=j;
            i++;
        }
        return true;
    }
    int maxDistance(vector<int>& pos, int m) {
        int n=pos.size();
        sort(pos.begin(),pos.end());
        if(m==2)
        {
            return pos[n-1]-pos[0];
        }
        int low,high;
        low=1;
        high=pos[n-1]-pos[0];
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(valid(mid,m,pos))
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return high;
    }
};