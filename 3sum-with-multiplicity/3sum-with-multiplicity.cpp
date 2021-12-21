class Solution {
public:
    long long int mod=1e9+7;
    int threeSumMulti(vector<int>& arr, int target) {
      int n=arr.size();
      vector<long long> c(101,0);
        for(int i=0;i<n;i++)
        c[arr[i]]++;
        long long int result=0;
        for(int i = 0; i <= 100; i++) {
            for(int j = i; j <= 100; j++) {
                int k = target-i-j;
                if(k<0 || k >100) continue;
                if(i == j && j==k) {
                    result+= (c[i] * (c[i]-1) * (c[i]-2) /6);
                }
                else if(i == j && j != k) {
                    result += ((c[i] * (c[i]-1) /2 ) * c[k]);
                }
                else if(i < j && j < k) {
                    result += (c[i] * c[j] * c[k]);
                }
            }
        }
        return (int)(result%mod);
    }
};