class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        vector<int> ans;
        int sumA=0,sumB=0;
        for(int i=0;i<aliceSizes.size();i++)
        {
            sumA+=aliceSizes[i];
        }
        for(int i=0;i<bobSizes.size();i++)
        {
            sumB+=bobSizes[i];
        }   
        int delta=(sumB-sumA)/2;
        for(int i=0;i<bobSizes.size();i++)
        {
            if(find(aliceSizes.begin(),aliceSizes.end(),bobSizes[i]-delta)!=aliceSizes.end())
             return {bobSizes[i]-delta,bobSizes[i]};   
        }   
        return ans;
    }
};