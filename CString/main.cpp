#ifdef _DEBUG
#include<iostream>
#endif // DEBUG
#include "mystring.h"
int main()
{
	CMyString a("Alma");
	a.Display();
	a.Display();
	a.Display();
	CMyString b;
	b = a;
	b.Display();
	CMyString c = "Banana";
	c.Display();
#ifdef _DEBUG
	std::cout << "Object count: " << c.GetObjectount() << std::endl;
#endif // DEBUG

	return 0;
}