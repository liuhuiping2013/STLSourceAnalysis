// file: 8compose.cpp
// gcc2.91[o] bcb4[x] vc6[x] 注：compose1() 是GCC独家产品

#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

class Shape
{
public:
	virtual void display() = 0;
};

class Rect: public Shape
{
public:
	virtual void display() {cout << "Rect ";}
};

class Circle: public Shape
{
public:
	virtual void display() {cout << "Circle ";}
};

class Square: public Rect
{
public:
	virtual void display() {cout << "Square ";}
};

int main(int argc, char const *argv[])
{
	std::vector<Shape*> V;
	V.push_back(new Rect);
	V.push_back(new Circle);
	V.push_back(new Square);
	V.push_back(new Circle);
	V.push_back(new Rect);

	// polymorphically
	for (int i = 0; i < V.size(); ++i)
	{
		(V[i])->display();
	}
	cout << endl;

	// polymorphically
	for_each(V.begin(), V.end(), mem_fun(&Shape::display)); // Rect Circle Square Circle Rect
	cout << endl;
	return 0;
}
