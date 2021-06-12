class Solution {
public:
    string reformatDate(string date) {
    date+=' ';
        string str="";
        int j=0;
        int c=0;
        string DD="",MM="",YYYY="";
        for(int i=0;i<date.size();i++)
        {
        if(date[i]==' ')
        {
          str=date.substr(j,i-j);
          j=i+1;
          c++;  
        }
        else
        continue;
            if(c==1)
            {
          if(str[1]-'0'<=9&&str[1]-'0'>=0)
          DD=str.substr(0,2);
          else
          {
string s(1, str[0]); 
DD="0"+s;   
          }    
            }
            else if(c==2)
            {
                if(str=="Jan")
                 MM="01";
                else if(str=="Feb")
                  MM="02";
                else if(str=="Mar")
                  MM="03";
                else if(str=="Apr")
                   MM="04";
                else if(str=="May")
                   MM="05";
                else if(str=="Jun")
                   MM="06";
                else if(str=="Jul")
                    MM="07";
                else if(str=="Aug")
                    MM="08";
                else if(str=="Sep")
                   MM="09";
                else if(str=="Oct")
                   MM="10";
                else if(str=="Nov")
                    MM="11";
                else if(str=="Dec")
                    MM="12";
            }
            else if(c==3)
            {
           YYYY=str;     
            }
            }
        return (YYYY+"-"+MM+"-"+DD);
    }
};