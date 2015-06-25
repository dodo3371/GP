#include "stdafx.h"

//클래스 함수 포인터
class C_DATA
{
private:
	int m_nData;
	void (C_DATA::*m_pFunc) (int);
public:
	C_DATA();
	void setData(int nData);
	void printData();
	void test(int nData);
};

int _tmain(int argc, _TCHAR* argv[])
{
	C_DATA cData;
	cData.test(100);
	cData.printData();
	return 0;
}

C_DATA::C_DATA() :
m_nData(0),
m_pFunc(NULL)
{
	m_pFunc = &C_DATA::setData;
}
void C_DATA::setData(int nData)
{
	m_nData = nData;
}
void C_DATA::printData()
{
	printf("%d\n", m_nData);
}
void C_DATA::test(int nData)
{
	(this->*m_pFunc)(nData);
}

/*
//함수 포인터
void printInt(int nData)
{
	printf("%d\n", nData);
}

int _tmain(int argc, _TCHAR* argv[])
{
	void (*pFunc) (int) = &printInt;
	(*pFunc)(10);
	return 0;
}
*/