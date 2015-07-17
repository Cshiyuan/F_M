#include "stdafx.h"
#include "Item_MS.h"
#include<fstream>

Item_MS::Item_MS()
{
	Item t;
	Item *tnext;  // ��Ϊ�²���Ŀд���ý��
	fstream file;  // ��ȡ�ļ�
	top = 0;
	file.open("items.dat", ios::in | ios::binary);  // ���ļ� ���������ļ��е����ݶ���
	while (1)
	{
		file.read((char*)&t, sizeof(t));
		for (int i = 0; i < t.getnextnumber(); i++)
		{
			tnext = new Item;
			file.read((char*)tnext, sizeof(t));  // �������
			t.next[i] = tnext;
		}
		if (!file) break;
		items[top] = t;
		top++;
	}
	file.close();
}
Item_MS::~Item_MS()
{
	Item t;  // ��Ϊ�ڶ���д����м�ý��
	fstream file;
	file.open("items.dat", ios::out | ios::binary);
	for (int i = 0; i < top; i++)  // ���е�һ���д��
	{
		if (items[i].getnote() == 1) continue;  // ����Ѿ�ɾ����д��,������һ��
		else  // ����д��
		{
			file.write((char*)&items[i], sizeof(t));  //����д��
			// ����Ŀ�²����Ŀд��
			for (int j = 0; j < items[i].getnextnumber(); j++)
			{
				file.write((char*)&(*items[i].next[j]), sizeof(t));  // ����д��
			}
			
		}
	}
}
void Item_MS::Item_MSadd(Item t)  // �����Ŀ
{
	items[top] = t;
	top++;
}
void Item_MS::Item_Msdel(int num)  // ɾ����Ŀ
{
	items[num].delitem();
}
Item * Item_MS::search(char *c)  // ������Ŀ�����ַ���ָ�������Ŀ��ָ��
{
	Item * prt;  // �������ָ�룬��������
	for (int i = 0; i < top; i++)  // ������Ŀ����ϵͳ�ĵ�һ��
	{
		prt = &items[i];  // ָ��ָ�����ϵͳ�еĹ�����Ŀ  
	    if (strcmp(c, prt->getname()))  // �����Ŀ��������ͬ
		return prt;  // �ҵ�����ָ����Ŀ��ָ��
		// �Ҳ���������һ�����
		if (items[i].getnextnumber() != 0)// �����Ŀ���²���Ŀ����Ϊ�� 
			for (int j = 0; j < items[i].getnextnumber(); j++)  // ������һ���ı���
			{
				prt = items[i].next[j];   // ָ���²��һ��
				if (strcmp(c, prt->getname()))   // ����һ����Ŀ�����ֽ����ж�  
				{
					return prt;  //�ҵ�����ָ��
				}
			}
	}
	return NULL;  // һֱû�ҵ��ͷ��ؿ�ָ��
}