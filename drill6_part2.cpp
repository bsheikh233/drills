#include "std_lib_facilities.h"

void print_array(ostream& os, int *a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		os << i + 1 << ". " << a[i] << endl;
	}
	cout << endl;
}

// -----------------------------------------------------------------------------

int main()
{
	// drill 1
	int x = 7;
	int *p1 = &x;

	// drill 2
	cout << "p1 = " << p1 << "\nx= " << *p1 << endl;

	// drill 3
	int array[] = { 1,2,4,8,16,32,64 };
	int *p2 = array;

	// drill 4
	cout << "p2 = " << p2 << endl;
	print_array(cout, p2, 7);

	// drill 5
	int* p3 = p2;

	// drill 6
	p2 = p1;

	// drill 7
	p2 = p3;

	// drill 8
	cout << "p1 = " << p1 << "/" << *p1 << endl;
	print_array(cout, p2, 7);

	// drill 9
	//We only allocated memory on stack, therefore we can't free it

	// drill 10
	int array1[] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };
	p1 = array1;

	// drill 11
	int array2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	p2 = array2;

	// drill 12
	for (int i = 0; i < 10; ++i)
		p2[i] = p1[i];

	// drill 13
	vector<int> v1{ 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };
	vector<int> v2{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (int i = 0; i < 10; ++i)
	{
		v2[i] = v1[i];
	}
	keep_window_open();
	return 0;
}