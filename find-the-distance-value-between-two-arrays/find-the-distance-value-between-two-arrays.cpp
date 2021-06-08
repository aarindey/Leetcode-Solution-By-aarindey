class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
   sort(arr1.begin(),arr1.end());
   bool x;
        int c=0;
        int j=0;
        while(j<arr1.size())
        {
            x=true;
        for(int i=0;i<arr2.size();i++)
        {
            if(abs(arr2[i]-arr1[j])<=d)
             x=false;   
        }
            j++;
            if(x)
             c++;   
               }
        return c;
    }
};