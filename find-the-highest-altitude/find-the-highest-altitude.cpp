class Solution {
public:
    int largestAltitude(vector<int>& gain) {
       
        int sum=0,max=0;
        for(int i=0;i<gain.size();i++)
        {sum+=gain[i];
           if(max<sum)
               max=sum;
        }
        return max;
        
    }
};