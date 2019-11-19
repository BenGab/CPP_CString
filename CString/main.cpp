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
	return 0;
}