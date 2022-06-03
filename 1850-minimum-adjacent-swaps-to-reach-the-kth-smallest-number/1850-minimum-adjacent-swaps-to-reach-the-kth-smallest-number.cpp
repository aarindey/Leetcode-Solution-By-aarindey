class Solution {
public:

    int countSteps(string s1, string s2) {
        int n = s1.length();
        
        int i = 0, j = 0;
        
        int result = 0;
        
        
        while (i < n) {
            j = i;
            while (s1[j] != s2[i]) j++;
			
            while (i < j) {
                swap(s1[j], s1[j-1]);
                j--;
                result++;
            }
            i++;
        }
        return result;
    }
    int getMinSwaps(string num, int k) {
        string f=num;
        while(k--)
        {
            next_permutation(f.begin(),f.end());
        }
        return countSteps(num,f);
    }
};