class Solution {
public:
vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
 map<int,int> mp;
 for(int i=0;i<arr1.size();i++) 
 {
     mp[arr1[i]]++;
 }
    int pos=0;
    for(int i=0;i<arr2.size();i++)
    {
        while(mp[arr2[i]]-->0)
        {
            arr1[pos]=arr2[i];
            pos++;
        }   
    }
    for(auto it:mp)
    {
        while(it.second-->0)
        {
            arr1[pos++]=it.first;
        }
    }
    return arr1;
 }
};