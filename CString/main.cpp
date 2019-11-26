#include "mystring.h"
#include<iostream>
#include<fstream>

using namespace std;

ostream& operator<<(ostream& os, CMyString& str)
{
	os << str.m_pchData;
	return os;
}

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