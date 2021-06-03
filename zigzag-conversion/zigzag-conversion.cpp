class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1)
            return s;
        int n=s.size();
        int row=0;
        string *str=new string[numRows];
        int step;
        for(int i=0;i<n;i++)
        {   
            str[row].push_back(s[i]);
            if(row==0)
             step=1;
            else if(row==numRows-1)
             step=-1;
              row+=step;  
        }
        s="";
        for(int i=0;i<numRows;i++)
        {
            s+=str[i];
        }
        return s;
    }
};