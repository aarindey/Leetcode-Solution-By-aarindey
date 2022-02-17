class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
   double ans;
    int n=customers.size();
    int currTime=customers[0][0];
    double total=0;
   for(auto customer:customers)
   {
        if(currTime>=customer[0])
        {
        currTime+=customer[1];
        total+=currTime-customer[0];
        }
        else
       {
       total+=customer[1];     
       currTime=customer[0]+customer[1];
       }
   }
     ans=(double)(total/(1.0*n));
        return ans;
    }
};