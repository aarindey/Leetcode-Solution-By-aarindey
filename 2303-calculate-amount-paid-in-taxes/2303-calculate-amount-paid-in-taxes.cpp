#define ll long long int
class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double ans;
        int n=brackets.size();
        ll taxable;
        for(int i=0;i<n;i++){
            if(i!=0)
            taxable=brackets[i][0]-brackets[i-1][0];
            else
            taxable=brackets[i][0];
            if(income>=taxable)
            {
                ll tax=taxable*brackets[i][1];
                ans+=((double)tax/100.0);
                income-=taxable; 
            }
            else if(income>0)
            {
                ans+=((income*brackets[i][1])/100.0);
                income=0;
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};