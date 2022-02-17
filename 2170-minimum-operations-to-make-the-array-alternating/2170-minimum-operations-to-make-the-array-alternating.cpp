class Solution {
public:
    int minimumOperations(vector<int>& nums) {
     unordered_map<int,int> mp1,mp2;
        int n=nums.size();
        if(n==1)
        return 0;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                mp1[nums[i]]++;
            }else{
                mp2[nums[i]]++;
            }
        }
        vector<pair<int,int>> odd,even;
        for(auto pr:mp1)
        {
            even.push_back({pr.second,pr.first});
        }
        for(auto pr:mp2)
        {
            odd.push_back({pr.second,pr.first});
        }
        sort(even.begin(),even.end(),greater<pair<int,int>>());
        sort(odd.begin(),odd.end(),greater<pair<int,int>>());
        if(odd[0].second!=even[0].second)
        return n-(odd[0].first+even[0].first);
        int even1,even2,odd1,odd2;
        odd1=odd[0].first;
        even1=even[0].first;
        odd2=(odd.size()==1)?0:odd[1].first;
        even2=(even.size()==1)?0:even[1].first;
        return min(n-(odd1+even2),n-(even1+odd2));
    }
};