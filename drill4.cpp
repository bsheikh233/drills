#include "std_lib_facilities.h"

/* Version 9.4.1
struct Date 
{
    int y;
    int m;
    int d;
};

void init_day(Date& dd, int y, int m, int d)
{
    if (m < 1 || m > 12) 
        error("Invalid month");
    if (d < 1 || d > 31) 
        error("Invalid day");
    dd.y = y;
    dd.m = m;
    dd.d = d;
}
void add_day(Date& dd, int n)
{
    dd.d += n;
    if (dd.d > 31) 
        dd.d %= 31;
}
ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.y << ',' << d.m << ',' << d.d << ')';
}
int main()
{
    Date today;
    init_day(today, 1978, 6, 25);
    Date tomorrow = today;
    add_day(tomorrow, 1);
    cout << today << endl << tomorrow << endl;
    //Date invalidDay;
    //init_day(invalidDay, 2009, 14, 32);
}
*/

/* 9.4.2
struct Date 
{
    int y, m, d;     
    Date(int y, int m, int d);     
    void add_day(int n);            
};

Date::Date(int yy, int mm, int dd)
    :y{ yy }, m{ mm }, d{ dd }
{
    if (m < 1 || 12 < m) 
        error("invalid month");
    if (d < 1 || 31 < d) 
        error("invalid day");
}

void Date::add_day(int n)
{
    d += n;
    if (d > 31) 
        d %= 31;
}

ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.y << ',' << d.m << ',' << d.d << ')';
}

int main()
try {
    Date today(1978, 6, 25);
    Date tomorrow = today;
    tomorrow.add_day(1);
    cout << today << endl << tomorrow << endl;
    //Date bad_day(2009, 14, 32);
}
catch (exception& e) {
    cerr << e.what() << endl;
    return 1;
}
catch (...) {
    cerr << "Unknown Problem" << endl;
    return 2;
}
*/


/* 9.4.3
class Date {
    int y, m, d;
public:
    Date(int y, int m, int d);      
    void add_day(int n);            
    int month() const { return m; }
    int day() const { return d; }
    int year() const { return y; }
};
Date::Date(int yy, int mm, int dd)
    :y{ yy }, m{ mm }, d{ dd }
{
    if (m < 1 || 12 < m) 
        error("invalid month");
    if (d < 1 || 31 < d) 
        error("invalid day");
}
void Date::add_day(int n)
{
    d += n;
    if (d > 31) 
        d %= 31;
}
ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.year() << ',' << d.month() << ',' << d.day() << ')';
}
int main()
try {
    Date today(1978, 6, 25);
    Date tomorrow = today;
    tomorrow.add_day(1);
    cout << today << endl << tomorrow << endl;
    //Date bad_day(2009, 14, 32);
}
catch (exception& e) {
    cerr << e.what() << endl;
    return 1;
}
catch (...) {
    cerr << "Unknown Problem" << endl;
    return 2;
}
*/


/* 9.7.1
enum class Month 
{
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

vector<string> month_tbl = { "January", "February", "March", "April",
                             "May", "June", "July", "August", "September",
                             "October", "November", "December" };

ostream& operator<<(ostream& os, Month m)
{
    return os << month_tbl[int(m)];
}

class Date {
    int y;
    Month m;
    int d;
public:
    Date(int y, Month m, int d);
    void add_day(int n);
    int year() const { return y; }
    Month month() const { return m; }
    int day() const { return d; }
};

Date::Date(int yy, Month mm, int dd)
    :y{ yy }, m{ mm }, d{ dd }
{
    if (d < 1 || 31 < d) 
        error("invalid day");
}

void Date::add_day(int n)
{
    d += n;
    if (d > 31) 
        d %= 31;
}

ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.year() << ',' << d.month() << ',' << d.day() << ')';
}

int main()
try {
    Date today(1978, Month::jun, 25);
    Date tomorrow = today;
    tomorrow.add_day(1);

    cout << today << endl << tomorrow << endl;

    //Date bad_day(2008, 15, 222);
}
catch (exception& e) {
    cerr << e.what() << endl;
    return 1;
}
catch (...) {
    cerr << "Unknown error" << endl;
    return 2;
}
*/


/*9.7.4
enum class Month
{
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

vector<string> month_tbl = { "January", "February", "March", "April",
                             "May", "June", "July", "August", "September",
                             "October", "November", "December" };

ostream& operator<<(ostream& os, Month m)
{
    return os << month_tbl[int(m)];
}

class Date {
    int y;
    Month m;
    int d;
public:
    Date(int y, Month m, int d);
    void add_day(int n);
    void add_month(int n);
    void add_year(int n);

    int year() const { return y; }
    Month month() const { return m; }
    int day() const { return d; }
};

Date::Date(int yy, Month mm, int dd)
    :y{ yy }, m{ mm }, d{ dd }
{
    if (d < 1 || 31 < d)
        error("invalid day");
}

void Date::add_day(int n)
{
    d += n;
    if (d > 31)
        d %= 31;
}

void Date::add_month(int n)
{
    int next = 0;
    if (next = (int(m) + n) > 12)
    {
        m = Month::jan;
        add_year(1);
    }
    else
        m = Month(next);
}

void Date::add_year(int n)
{
    y += n;
}

ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.year() << ',' << d.month() << ',' << d.day() << ')';
}

int main()
try {
    Date today(1978, Month::jun, 25);
    Date tomorrow = today;
    tomorrow.add_day(1);

    cout << today << endl << tomorrow << endl;

    //Date bad_day(2008, 15, 222);
}
catch (exception& e) {
    cerr << e.what() << endl;
    return 1;
}
catch (...) {
    cerr << "Unknown error" << endl;
    return 2;
}
*/