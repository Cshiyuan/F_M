#pragma once
#include"Item.h"
#define MAXn 10  // ���ϵͳ�ܹ�ʹ�õ������Ŀ������
class Item_MS
{
public:
	Item_MS();
	~Item_MS();
	void Item_MSadd(Item t);  // �����Ŀ
	void Item_Msdel(int num);  // ɾ����Ŀ

	Item * search(char *name);  // ������Ŀ�����ַ���ָ�������Ŀ��ָ��
private:
	Item items[MAXn];  //��Ŀ����
	int top;  // ��¼��Ŀ������
};

