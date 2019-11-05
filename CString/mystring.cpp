#include <iostream>
#include "mystring.h"

using namespace std;

inline void strcpy(int from, int length, const char * src, char* dst)
{
	for (size_t i = 0; i < length; i++)
	{
		dst[from + i] = src[i];
	}
}

inline int mystrlen(const char* src)
{
	int datalen = 0;
	while (src[datalen++] != '\0');
	return datalen;
}

CMyString::CMyString()
{
	m_pchData = nullptr;
	m_nDataLength = 0;
}

CMyString::CMyString(const char * psz)
{
	if (!psz)
	{
		m_pchData = nullptr;
		m_nDataLength = 0;
		return;
	}

	m_nDataLength = mystrlen(psz);
	m_pchData = new char[m_nDataLength];

	strcpy(0, m_nDataLength, psz, m_pchData);
}

CMyString::CMyString(char ch, int nRepeat)
{
	m_nDataLength = nRepeat;
	m_pchData = new char[nRepeat];

	for (int i = 0; i < nRepeat - 1; i++)
	{
		m_pchData[i] = ch;
	}
}

CMyString::~CMyString()
{
	delete[] m_pchData;
	m_pchData = nullptr;
	m_nDataLength = 0;
}

int CMyString::GetLenght() const
{
	return m_nDataLength;
}

char CMyString::GetAt(int nIndex) const
{
	if (nIndex > m_nDataLength - 1)
	{
		throw CStringException("Inex out of Range");
	}

	return m_pchData[nIndex];
}

void CMyString::SetAt(int nIndex, char ch)
{
	if (nIndex > m_nDataLength - 1)
	{
		throw CStringException("Inex out of Range");
	}

	m_pchData[nIndex] = ch;
}

void CMyString::Append(const char * psz)
{
	int srclen = mystrlen(m_pchData);
	int appendlen = mystrlen(psz);
	char* newData = new char[srclen + appendlen];
	strcpy(0, srclen, m_pchData, newData);
	strcpy(srclen, appendlen, psz, newData);
}

void CMyString::Display() const
{
	cout << m_pchData << endl;
}

CStringException::CStringException(const char * message)
{
	*m_pMessage = *message;
}

char * CStringException::GetMessage()
{
	return m_pMessage;
}
