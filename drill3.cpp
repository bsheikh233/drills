#include "std_lib_facilities.h"

void swap_v(int a, int b)
{
	int temp; 
	temp = a, a = b; 
	b = temp;
}

void swap_r(int& a, int& b)
{
	int temp;
	temp = a, a = b;
	b = temp;

}

/*void swap_cr(const int& a, const int& b)
{
	int temp; 
	temp = a, a = b; 
	b = temp;

}*/

int main()
{

	int x = 7;
	int y = 9;

	swap_v(x, y);
	cout << x << "," << y << endl; // only the local variables of the function got swapped
	
	swap_r(x, y);
	cout << x << "," << y << endl; // this one actually got swapped

	//swap_cr(x, y); //does not compile


	swap_v(7, 9);		//swaps but does not return anything
	//swap_r(7, 9);		//no address to swap 
	//swap_cr(7, 9);	//does not compile


//------------------------------------------------------------------------------------------------------------------

	const int cx = 7;
	const int cy = 9;

	swap_v(cx, cy);		//only the local variables of the function got swapped
	cout << cx << "," << cy << endl;

	//swap_r(cx, cy);	//not allowed to swap const
	//swap_cr(cx, cy);	//does not compile

	swap_v(7.9, 9.9);		//swaps but does not return anything
	//swap_r(7.9, 9.9);		//no address to swap 
	//swap_cr(7.9, 9.9);	//does not compile

//------------------------------------------------------------------------------------------------------------------

	double dx = 7.7;
	double dy = 9.9;

	swap_v(dx, dy);		//only the local variables of the function got swapped
	cout << dx << "," << dy << endl;
	//swap_r(dx, dy);	//does not compile because there is no address for int
	//swap_cr(dx, dy);	//does not compile

	swap_v(7.7, 9.9);	//swaps but does not return anything
	//swap_r(7.7, 9.9); //no address to swap
	//swap_cr(7.7, 9.9);//does not compile

	keep_window_open();

	return 0;
}