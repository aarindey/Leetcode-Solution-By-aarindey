class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
       int count_zeroes=0;
       for(int i=0;i<arr.size();i++)
       {
           if(arr[i]!=0&&find(arr.begin(),arr.end(),arr[i]*2)!=arr.end())
            return true;
           if(arr[i]==0)
           count_zeroes++;
       }   
    if(count_zeroes>1)
    return true;
         
    return false;
    }
};