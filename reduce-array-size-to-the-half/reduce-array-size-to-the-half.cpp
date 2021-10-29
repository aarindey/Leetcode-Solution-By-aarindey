class Solution {
public:
    int minSetSize(vector<int>& arr) {
       int ans=0;
    unordered_map<int,int> mp;
    for(int a:arr)
    {
        mp[a]++;
    }
    vector<int> freq;
    for(auto pr:mp)
    {
        freq.push_back(pr.second);
    }
        sort(freq.begin(),freq.end(),greater<int>());
        int i=0;
        int sum=0,count=0;
        while(sum<arr.size()/2)
        {
            sum+=freq[i];
            i++;
            count++;
        }
        return count;
    }
};