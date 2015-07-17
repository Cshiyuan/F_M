#include "stdafx.h"
#include "Bdata.h"
#include<iomanip>  //Ϊ��ʹ��setw����


Bdata::Bdata()
{

}
Bdata::Bdata(int _year, int _month, int _day) :year(_year), month(_month), day(_day)
{

}
Bdata::~Bdata()
{

}
Bdata::Bdata(const Bdata & b)  // �������캯��
{
	year = b.year;
	month = b.month;
	day = b.day;
}
ostream & operator <<(ostream & output, Bdata b)  // �����<<������
{
	output << setw(6) << b.year << setw(6) << b.month << setw(6) << b.day;
	return output;
}
istream & operator >>(istream & input, Bdata b)  // �����>>������
{
	input >> b.year >> b.month >> b.day;
	return input;
}
