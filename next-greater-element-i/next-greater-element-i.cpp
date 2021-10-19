//496. Next Greater Element I
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      int num1;
        vector<int> ans;
      for(int i=0;i<nums1.size();i++)
      {
          num1=nums1[i];
          vector<int>::iterator it=find(nums2.begin(),nums2.end(),nums1[i]);
        while(it!=nums2.end())
          {
              if(*it>num1)
              {
               ans.push_back(*it);
               break;
              }
              it++;
          } 
            if(it==nums2.end())
           ans.push_back(-1);
      }   
      return ans;  
    }
};