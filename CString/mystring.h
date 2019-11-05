#ifndef CSTRING_H
#define CSTRING_H

class CStringException
{
public:
	CStringException(const char* message);
	char* GetMessage();
private:
	char* m_pMessage;
};


class CMyString
{
private:
	char*		m_pchData;
	int			m_nDataLength;
public:
	CMyString();
	CMyString(const char* psz);
	CMyString(char ch, int nRepeat = 1);
	~CMyString();

	int GetLenght() const;
	char GetAt(int nIndex) const;
	void SetAt(int nIndex, char ch);
	void Append(const char* psz);
	void Display() const;
};
#endif
