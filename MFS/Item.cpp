#include "stdafx.h"
#include "Item.h"


Item::Item(const char* _name)
{
	sum = 0;  // ��Ŀ�����ܽ��Ϊ0
	top = 0;   // ��Ŀ������ĿΪ0
	nextnumber = 0;  // ��һ����Ŀ������Ϊ0
	note = 0;  // ����ɾ�����
	strcpy_s(name, strlen(_name) + 1, _name);  // ��ʼ������

	for (int i = 0; i < MAXc; i++)
		next[i] = NULL;   // ��һ�����Ŀ����Ϊ��
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < 2; j++)
			member_money[i][j] = 0;   // ��ʼ����Ŀ������Ŀ
}
Item::Item()  // Ĭ�Ϲ��캯��
{

}
Item::~Item()
{

}
void Item::Addconsumption(int key, double money)
{
	
	if (top >= MAX)
	{
		cout << "��Ŀ���������" << endl;
		return;
	}
	sum = sum + money;  // �����ܽ������
	member_money[top][0] = key;  // ����key
	member_money[top][1] = money;  // ����money
	top;  // ��Ŀ����һ
	return;
}
void Item::Addnext(const char* _name)  // ����Ŀ����һ�������Ŀ
{
	
	this -> next[nextnumber] = new Item(_name);
	this -> nextnumber++;
	return;
}
void Item::changename(const char* _name)  // �޸�����
{
	strcpy_s(name, strlen(_name) + 1, _name);
}
void Item::changemoney(double _money)   // �޸Ľ��
{
	sum = _money;
}
void Item::delitem()  // ����ɾ�����
{
	note = 1;
}
int Item::getnote()  // ���ɾ�����
{
	return note;
}
int Item::getnextnumber()  // ������һ����Ŀ������
{
	return nextnumber;
}
char * Item::getname()  // ������Ŀ������
{
	return name;
}
