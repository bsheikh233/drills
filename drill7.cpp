#include "std_lib_facilities.h"

template <typename T>
struct S
{
	T val;

public:
	S()
	{
		val = 0;
	}
	S(T x)
	{
		val = x;
	}

	T& get();

	T& get() const
	{
		return val;
	}

	void operator=(const T& x)
	{
		val = x;
	}
	
	/*void set(const T& x)
	{
		val = x;
	}*/
	

};

template<typename T>
T& S<T> :: get()
{
	return val;
}

template <typename T>
void read_val(T& v)
{
	cin >> v;
}

int main()
{
	S <int> a(1);
	S<char> b('A');
	S<double> c(1.1);
	S<string> d("String A");
	S<vector<int>> e({ 1, 2, 3 });
	
	/*
	cout << a.val << endl;
	cout << b.val << endl;
	cout << c.val << endl;
	cout << d.val << endl;
	for(int i : e.val)
	cout << i << " ";
	*/

	cout << a.get() << endl;
	cout << b.get() << endl;
	cout << c.get() << endl;
	cout << d.get() << endl;
	for (int i : e.get())
		cout << i << " ";
	cout << endl;

	int x; 
	read_val(x); 
	S <int> a1(x);

	char y; 
	read_val(y);
	S<char> b1(y);
	
	double z;
	read_val(z);
	S<double> c1(z);

	cout << a1.get() << endl;
	cout << b1.get() << endl;
	cout << c1.get() << endl;

	return 0;
}