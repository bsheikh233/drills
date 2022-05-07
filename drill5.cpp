#include "std_lib_facilities.h"
// 1
struct Point 
{
    int x;
    int y;
};

// 2. Make Point input-able
istream& operator>>(istream& is, Point& p)
{
    int xx, yy;
    is >> xx;
    is >> yy;
    p.x = xx;
    p.y = yy;
    return is;
}

// 3. Make points printable
ostream& operator<< (ostream& os, Point& p)
{
    return os << '(' << p.x << ',' << p.y << ')';
}

int main()
try {
    // 2
    cout << "Please enter seven sets of x, y points: (in the form: 4 5 )" << endl;
    vector <Point> original_points; 

    while (original_points.size() < 7) {
        Point p;
        cin >> p;
        original_points.push_back(p);
    }

    // 3
    for (Point p : original_points)
        cout << p;
    cout << endl;

    // 4
    string fname = "mydata.txt";
    ofstream fout(fname);
    if (!fout) 
        error("could not open file ", fname);

    for (Point p : original_points)
        fout << p;
    fout.close();

    // 5
    vector <Point> processed_points;
    ifstream fin(fname);
    if (!fin)
        error("can't open input file ", fname);
    for (Point p; fin >> p; )
        processed_points.push_back(p);

    for (Point p : processed_points)
        cout << p;
    cout << endl;

    if (original_points.size() != processed_points.size())
        cout << "Something's wrong!" << endl;
}
catch (exception& e) {
    cerr << "Error: " << e.what() << endl;
    return 1;
}
catch (...) {
    cerr << "Something terrible has happened!" << endl;
    return 2;
}