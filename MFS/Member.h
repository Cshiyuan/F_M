#pragma once

#include"Bdata.h"
#include<iostream>
#include<iomanip>  // Ϊ��ʹ��setw();
using namespace std;
class Member
{
public:

	Member();  // Ĭ�Ϲ��캯��
	Member(char* _name, char* _sex, Bdata _Bdate, int _age, double _height, double _weight); // ʹ�ó�ʼ���б�
	
	virtual ~Member();

	friend ostream & operator << (ostream & output, const Member &m);  // ���������
	friend istream & operator >> (istream & input, Member &m);   // ��ȡ��ȡ���������

	void changename(const char *_name);  // �޸�����
	void changesex(const char *_sex);  // �޸��Ա�
	void changeBdate(const Bdata _Bdate);  // �޸�����
	void changeage(const int _age);  // �޸�����
	void changeheight(const double _height);  // �޸����
	void changeweight(const double _weight);  // �޸�����

private:
	char name[50];  // ����
	char sex[50];  // �Ա�
	Bdata Bdate;  // ��������
	int age;  // ����
	double height; // ���
	double weight;  // ����

};

