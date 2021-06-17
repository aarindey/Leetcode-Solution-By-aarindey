class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        vector<int> vec;
        for(int i=0;i<arr.size()-1;i++)
        {
            for(int j=i+1;j<arr.size();j++)
            {
                if(arr[j]<arr[i])
                {
                    int temp=arr[j];
                    arr[j]=arr[i];
                    arr[i]=temp;
                }
            }}
    for(int i=0;i<arr.size()-2;i++)
    {
        if((arr[i+1]-arr[i])!=(arr[i+2]-arr[i+1]))
            return false;
    }
        return true;
}};