#pragma once
#define MAX 10  // �궨����Ŀ��������Ŀ // ����ǰԤ���������ú�ֵ�滻����
#define MAXc 5  // ������һ����֧��Ŀ�������Ŀ
#include<iostream>
using namespace std;
class Item
{
public:
	 Item(const char *name);  // ���캯��
	 Item();  // Ĭ�Ϲ��캯��
	~Item();
	//Item(Item & _t);  // �������캯��

	void Addconsumption(int key, double money);  // ����key����ӳ�Ա����Ŀ������
	void Addnext(const char *name);  // ������һ�����Ŀ

	void changename(const char *name);  // �޸���Ŀ������
	void changemoney(const double money);  // �޸���Ŀ�Ľ��

	void delitem();  // ɾ����Ŀ  // Ҳ���ǽ�note��Ϊ1

	int getnote();  // ���ɾ�����
	int getnextnumber();  // �����Ŀ�²����Ŀ��

	char *getname();  // �����Ŀ������
	double getmoney();  // ��ý��

    Item *next[MAXc];   // ��һ�����֧��Ŀ��û����һ����ΪNULL  //��Ӧ��Ϊnextnumber
	                    // ָ������

	
private:
	
	char name[50];   // ��Ŀ����
	double sum;  // ����Ŀ�����ܽ��
	double member_money[MAX][2];  // ֧��  [i][0]��ʾkey��[i][1]��ʾ�����˶���Ǯ  //��Ӧ��Ϊtop

	// ��������ݳ�ԱΪָʾ�õ�����
	int top;   // �ܹ��ж��ٸ���Ŀ��Ŀ
	int nextnumber;  // ������һ�����Ŀ

	int note;  // ɾ�����
};

