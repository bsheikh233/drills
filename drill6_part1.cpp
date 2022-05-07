#include "std_lib_facilities.h"



void print_array10(ostream& os, int *a)
{
	for (int i = 0; i < 10; ++i)
	{
		os << i + 1 << ". " << a[i] << endl;
	}
	os << endl;
}

void print_array(ostream& os, int *a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		os << i + 1 << ". " << a[i] << endl;
	}
	os << endl;
}

void print_vector(ostream& os, vector<int>& v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		os << i + 1 << ". " << v[i] << endl;
	}
	os << endl;
}


int main()
{
	// drill 1
	int *array = new int[10];

	// drill 2 - filled with garbage
	for (int i = 0; i < 10; ++i)
	{
		cout << i + 1 << ". " << array[i] << endl;
	}
	cout << endl;

	/* drill 3
	delete [] array;*/

	// drill 4
	print_array10(cout, array);
	delete [] array;

	// drill 5
	array = new int[10]{100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
	print_array10(cout, array);
	delete []array;

	// drill 6 and 7 together
	array = new int[11]{ 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110 };
	print_array(cout, array, 11);
	delete[] array;

	// drill 8
	array = new int[20]{ 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119 };
	print_array(cout, array, 20);
	delete [] array;

	// drill 10
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i + 100);
	}
	print_vector(cout, v);
	v.clear();

	for (int i = 0; i < 11; i++)
	{
		v.push_back(i + 100);
	}
	print_vector(cout, v);
	v.clear();

	for (int i = 0; i < 20; i++)
	{
		v.push_back(i + 100);
	}
	print_vector(cout, v);
	v.clear();

	keep_window_open();
	return 0;
}