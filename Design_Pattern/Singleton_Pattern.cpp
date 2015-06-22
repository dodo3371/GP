#include "stdafx.h"

class C_DATA
{
private:
	int m_nData;
	static C_DATA * m_pData;
private:
	C_DATA();
public:
	static C_DATA * getInstanse();
	void setData(int nData);
	void printData();
};

C_DATA * C_DATA::m_pData = NULL; //singleton pattern

C_DATA * C_DATA::getInstanse()
{
	if (!m_pData)
		m_pData = new C_DATA;
	return m_pData;
}

int _tmain(int argc, _TCHAR* argv[])
{
	C_DATA::getInstanse()->setData(100);
	C_DATA::getInstanse()->printData();
	return 0;
}

C_DATA::C_DATA() : m_nData(0)
{
}

void C_DATA::setData(int nData)
{
	m_nData = nData;
}

void C_DATA::printData()
{
	printf("%d\n", m_nData);
}