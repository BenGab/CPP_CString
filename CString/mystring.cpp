#include <iostream>
#include "mystring.h"

using namespace std;

inline void strcpy(int from, int length, const char * src, char* dst)
{
	for (size_t i = 0; i < length; i++)
	{
		dst[from + i] = src[i];
	}
	dst[from + length] = '\0';
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
	m_pchData = new char[m_nDataLength + 1];

	strcpy(0, m_nDataLength, psz, m_pchData);
}

CMyString::CMyString(const CMyString& str)
{
	if (str.m_pchData == nullptr)
	{
		return;
	}

	m_nDataLength = mystrlen(str.m_pchData);
	m_pchData = new char[m_nDataLength + 1];
	strcpy(0, m_nDataLength, str.m_pchData, m_pchData);
}

CMyString::CMyString(char ch, int nRepeat)
{
	m_nDataLength = ++nRepeat;
	m_pchData = new char[nRepeat];

	for (int i = 0; i < nRepeat - 1; i++)
	{
		m_pchData[i] = ch;
	}
}

CMyString::~CMyString()
{
	delete[] m_pchData;
}

CMyString& CMyString::operator=(const CMyString & str)
{
	if (this == &str)
	{
		return *this;
	}

	m_nDataLength = str.m_nDataLength;
	delete[] m_pchData;
	m_pchData = new char[m_nDataLength + 1];
	strcpy(0, m_nDataLength - 1, str.m_pchData, m_pchData);
	return *this;
}

int CMyString::GetLenght() const
{
	return m_nDataLength;
}

char& CMyString::operator[](int nIndex) const
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
	strcpy(srclen - 1, appendlen, psz, newData);
	delete[] m_pchData;
	m_pchData = newData;
	m_nDataLength = srclen + appendlen - 2;
}

void CMyString::Display() const
{
	cout << m_pchData << endl;
}

void CMyString::Reverse()
{
	char* newData = new char[m_nDataLength + 1];
	int j = 0;
	for (int i = (m_nDataLength - 1); i >= 0; i--)
	{
		newData[j++] = m_pchData[i];
	}
	newData[j] = '\0';
	delete m_pchData;
	m_pchData = newData;
}

CStringException::CStringException(const char * message)
{
	*m_pMessage = *message;
}

char * CStringException::GetMessage()
{
	return m_pMessage;
}
