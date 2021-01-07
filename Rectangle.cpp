#include <iostream>
using namespace std;

class Rectangle
{
private:
	int length;
	int width;

public:
	Rectangle(int length_, int width_) : length(length_), width(width_) {};
	~Rectangle() {};
	int areaCal (void);
	int circumferenceCal (void);
};

int Rectangle::areaCal (void)
{
	return length * width;
}

int Rectangle::circumferenceCal (void)
{
	return 2 * (length+width);
}

class Square : public Rectangle
{
private:
	int edge;
public:
	Square(int length_, int width_, int edge_) : Rectangle(length_,width_), edge(edge_) {};
	~ Square() {};
	virtual int areaCal (void);
	virtual int circumferenceCal (void);
};

int Square::areaCal (void)
{
    
	return edge * Rectangle::areaCal();
}

int Square::circumferenceCal (void)
{
	return 4 * edge;
}

int main (void)
{
	Rectangle R1(20,10);
	Square S1(20,10,30);
    Square* S2 = new Square(20,10,50);
	cout << R1.areaCal() << endl;
	cout << R1.circumferenceCal() << endl;

	cout << S1.areaCal() << endl;
	cout << S1.circumferenceCal() << endl;

    cout << S2->areaCal() << endl;
	cout << S2->circumferenceCal() << endl;
	return 0;
}