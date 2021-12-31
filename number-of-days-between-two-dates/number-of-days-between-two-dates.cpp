class Solution {
public:

//converting string to int
int stringToInt(string s)
{
    stringstream ss(s);
    int x = 0;
    ss>>x;
    
    return x;
}

//check if the year is leap year
bool isLeapYear(int year)
{
    if (year % 400 == 0)
        return true;

   else if (year % 100 == 0)
        return false;

   else if (year % 4 == 0)
        return true;

   else
        return false;
}

//function to return number of days between 1900-01-01 to the present date
int fDate(string d)
{
    string year = d.substr(0, 4);
    string mon = d.substr(5, 2);
    string date = d.substr(8, 2);
    
    int y = stringToInt(year);
    int m = stringToInt(mon);
    int da = stringToInt(date);
    
    int days = 0;
    
	//adding days of year
    for(int i = 1900; i < y; i++)
    {
        if(isLeapYear(i))
            days += 366;
        else
            days += 365;
    }
    
	//adding days of months
    for(int i = 1; i < m; i++)
    {
        if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10)
            days += 31;
        else if(i == 4 || i == 6 || i == 9 || i == 11)
            days += 30;
        else if(i == 2)
        {
            if(isLeapYear(y))
                days += 29;
            else
                days += 28;
        }
    }
    
	//adding final dates
    days += da;
    
    return days;
}

int daysBetweenDates(string date1, string date2) {
    return abs(fDate(date1) - fDate(date2));
}
};