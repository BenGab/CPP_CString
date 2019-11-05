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
	return 0;
}