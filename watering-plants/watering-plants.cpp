class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int ans=0;
        long long int curr=capacity;
        int i=0;
        while(i<plants.size())
        {
            while(i<plants.size()&&curr>=plants[i])
            {
                curr-=plants[i];
                ans++;
             
                i++;
            }
            if(i<plants.size()&&curr<plants[i])
            {
                ans+=2*(i);
                curr=capacity;
              
            }
        }
        return ans;
    }
};