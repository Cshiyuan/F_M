#pragma once
#include"Item.h"
#define MAXn 10  // ���ϵͳ�ܹ�ʹ�õ������Ŀ������
class Item_MS
{
public:
	Item_MS();
	~Item_MS();
	void Item_MSadd(Item t);  // �����Ŀ

	//������Ŀ�������޸�
	void Item_Msdel(char *c);  // ɾ����Ŀ
	void changemoney(char *c, double money);  // �޸���Ŀ�Ľ��
	void changename(char *c, char *name);  // �޸���Ŀ������

	void show(int number);  // �����Ŀ�����е���Ϣ���������²���Ŀ

	Item * search(char *name);  // ������Ŀ�����ַ���ָ�������Ŀ��ָ��
private:
	Item items[MAXn];  //��Ŀ����
	int top;  // ��¼��Ŀ������
};

