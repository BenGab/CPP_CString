#include "mystring.h"
int main()
{
	CMyString a("Alma");
	a.Display();
	a.Append("Korte");
	a.Display();
	a.Reverse();
	a.Display();
	return 0;
}