#pragma once

#include<string>
using namespace std;
class Bdata
{
public:
	Bdata();  // Ĭ�Ϲ��캯��
	Bdata(int _year, int _month, int _day);
	Bdata(const Bdata & B);  // �������캯��
	virtual ~Bdata();
	friend ostream &operator<<(ostream & output, Bdata b);  //���������
	friend istream &operator>>(istream & input, Bdata b);
protected:
private:
	int year;  // ������
	int month;  //������
	int day;  // ������
};
