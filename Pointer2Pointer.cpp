#include <iostream>
#include <iomanip> 
using namespace std;

void RectanglePointer (int * _length, int * _width, int * _area, int * _boundary)
{
	*_area = *_length * *_width;
	*_boundary = 2 * (*_length + *_width);
}

void RectangleReference (int & _length, int & _width, int & _area, int & _boundary)
{
	_area = _length * _width;
	_boundary = 2 * (_length + _width);
}

void RectangleMultiplePointer (int ** _length, int ** _width, int ** _area, int ** _boundary)
{
	**_area = **_length * **_width;
	**_boundary = 2 * (**_length + **_width);
}

int main ()
{
	int length = 24;
	int width = 34;
	int area = 0;
	int boundary = 0;
	RectanglePointer(&length, &width, &area, &boundary);
	cout << area << " and " << boundary << endl;

	RectangleReference(length, width, area, boundary);
	cout << area << " and " << boundary << endl;

	int * p_length = &length;
	int * p_width = &width;
	int * p_area = &area;
	int * p_boundary = &boundary;

	RectanglePointer(p_length, p_width, p_area, p_boundary);
	cout << area << " and " << boundary << endl;

	int ** pp_length = &p_length;
	int ** pp_width = &p_width;
	int ** pp_area = &p_area;
	int ** pp_boundary = &p_boundary;

	RectangleMultiplePointer(pp_length, pp_width, pp_area, pp_boundary);
	cout << area << " and " << boundary << endl;

	cout << "Size of int is " << sizeof(int) << endl;
	cout << &boundary+1 << " and " << p_boundary+1 << " and "  << *pp_boundary+1 << endl;

	uint8_t * OneByte = (uint8_t *) &boundary;
	boundary = 1025;
	cout << boundary << " and " << *(p_boundary+1) << " and " << *(*pp_boundary+1) << endl;
	cout << OneByte << " and " << *OneByte << " then "  << OneByte+1 << " and " << *(OneByte+1) << endl;

	// Dereference to the variable is corresponding to levels of the pointer
	// int a = 0;
	// Level 1: int * p_a = &a; *p_a = 1;
	// Level 2: int ** pp_a = &p_a; **pp_a = 2;
	// Level 3: int *** ppp_a = &pp_a; ***ppp_a = 3;

	cout << "1``````````````````````````````````````````````````````````````````````````````````````````1" << endl;
	cout << *pp_length << " and " << *pp_width << " and " << *pp_area << " and " << *pp_boundary << endl;
	cout << &length << " and " << &width << " and " << &area << " and " << &boundary << endl;
	cout << p_length << " and " << p_width << " and " << p_area << " and " << p_boundary << endl;

	cout << "2``````````````````````````````````````````````````````````````````````````````````````````2" << endl;
	cout << length << " and " << width << " and " << area << " and " << boundary << endl;
	cout << *p_length << " and " << *p_width << " and " << *p_area << " and " << *p_boundary << endl;
	cout << **pp_length << " and " << **pp_width << " and " << **pp_area << " and " << **pp_boundary << endl;

	cout << "3``````````````````````````````````````````````````````````````````````````````````````````3" << endl;
	cout << &p_length << " and " << &p_width << " and " << &p_area << " and " << &p_boundary << endl;
	cout << pp_length << " and " << pp_width << " and " << pp_area << " and " << pp_boundary << endl;

	return 0;
}