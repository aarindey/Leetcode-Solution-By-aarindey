class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
  int n=tops.size();
vector<int> top(7,0);
 vector<int> bottom(7,0);
   vector<int> same(7,0);     
       int minRotation=INT_MAX; 
       for(int i=0;i<n;i++)
       {
           top[tops[i]]++;
           bottom[bottoms[i]]++;
           if(tops[i]==bottoms[i])
             same[tops[i]]++;  
       }
       for(int i=1;i<7;i++)
       {
           if((top[i]+bottom[i]-same[i])==n)
            minRotation= min(minRotation,min(top[i],bottom[i])-same[i]);   
       }
        return minRotation==INT_MAX?-1:minRotation;
    }
};