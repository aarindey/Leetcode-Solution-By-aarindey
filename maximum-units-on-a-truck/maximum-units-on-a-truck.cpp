class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
 int ans=0;        
sort(boxTypes.begin(),boxTypes.end(),comp);
        for(auto x:boxTypes)
     {
            if(truckSize==0)
             break;
            ans+=min(x[0],truckSize)*x[1];
            truckSize-=min(x[0],truckSize);
    }
        return ans;
    }
    bool static comp(vector<int> vec1,vector<int> vec2)
    {
        return (vec1[1]>vec2[1]);
    }
};