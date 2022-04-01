class Solution {
public:
    void reverseString(vector<char>& s) {
       int start=0,e=s.size()-1;
        while(start<e)
        {
            swap(s[start],s[e]);
            start++;
            e--;
        }
    }
};